/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:41:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/18 14:03:55 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ray_type_v_h(t_data *data,
	float distance_horizontal, float distance_vertical, int i)
{
	if (distance_horizontal < distance_vertical)
	{
		data->rays[i].x = data->rays[i].h_x;
		data->rays[i].y = data->rays[i].h_y;
		data->rays[i].distance_to_wall = distance_horizontal;
		data->rays[i].x_texture = (int)(data->rays[i].x) % 64;
		if (data->rays[i].rotation > 0 && data->rays[i].rotation < PI)
			data->rays[i].p = 1;
		else
			data->rays[i].p = 0;
	}
	else
	{
		data->rays[i].x = data->rays[i].v_x;
		data->rays[i].y = data->rays[i].v_y;
		data->rays[i].distance_to_wall = distance_vertical;
		data->rays[i].x_texture = (int)(data->rays[i].y) % 64;
		if ((data->rays[i].rotation)
			< PI / 2 || data->rays[i].rotation > 3 * PI / 2)
				data->rays[i].p = 2;
		else
			data->rays[i].p = 3;
	}
}

void	get_ray_height(t_data *data, int i)
{
	data->rays[i].diference_angle = (data->player.rotation)
		- data->rays[i].rotation;
	if (data->rays[i].diference_angle < 0)
		data->rays[i].diference_angle += 2 * PI;
	if (data->rays[i].diference_angle > 2 * PI)
		data->rays[i].diference_angle -= 2 * PI;
	data->rays[i].distance_to_wall = (data->rays[i].distance_to_wall)
		* cos(data->rays[i].diference_angle);
	data->rays[i].line_height = (MINI_MAP_SIZE * WINDOW_WIDTH)
		/ data->rays[i].distance_to_wall;
	if (data->rays[i].line_height > WINDOW_WIDTH)
		data->rays[i].line_height = WINDOW_WIDTH;
	data->rays[i].line_o = WINDOW_HEIGHT / 2
		- data->rays[i].line_height / 2;
}

void	fix_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 320)
	{
		if (i != 0 && data->rays[i - 1].p == data->rays[i + 1].p)
			data->rays[i].p = data->rays[i - 1].p;
		if (i != 0 && data->rays[i - 1].p == data->rays[i + 5].p)
		{
			data->rays[i].p = data->rays[i - 1].p;
			data->rays[i + 1].p = data->rays[i - 1].p;
			data->rays[i + 2].p = data->rays[i - 1].p;
			data->rays[i + 3].p = data->rays[i - 1].p;
			data->rays[i + 4].p = data->rays[i - 1].p;
			data->rays[i + 5].p = data->rays[i - 1].p;
		}
		i++;
	}
}

void	check_intersections_utils(t_data *data,
		float *distance_horizontal, float *distance_vertical, int i)
{
	*distance_horizontal = distance_btw_two_points(data->player.x,
			data->player.y, data->rays[i].h_x, data->rays[i].h_y);
	*distance_vertical = distance_btw_two_points(data->player.x,
			data->player.y, data->rays[i].v_x, data->rays[i].v_y);
	get_ray_type_v_h(data, *distance_horizontal, *distance_vertical, i);
	get_ray_height(data, i);
}

void	check_intersections(t_data *data)
{
	float	distance_horizontal;
	float	distance_vertical;
	int		i;

	i = 0;
	while (i < 320)
	{
		data->rays[i].rotation = (data->player.rotation - 30 * DG)
			+ (DG * 60 / 320) * i;
		if (data->rays[i].rotation < 0)
			data->rays[i].rotation += 2 * PI;
		if (data->rays[i].rotation > 2 * PI)
			data->rays[i].rotation -= 2 * PI;
		check_intersections_h(data, &data->rays[i].h_x, &data->rays[i].h_y,
			data->rays[i].rotation);
		check_intersections_v(data, &data->rays[i].v_x,
			&data->rays[i].v_y, data->rays[i].rotation);
		check_intersections_utils(data, &distance_horizontal,
			&distance_vertical, i);
		i++;
	}
	fix_texture(data);
}
