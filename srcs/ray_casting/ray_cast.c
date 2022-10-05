/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:41:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/05 15:07:04 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_data *data, float x, float y)
{
	int	i;

	i = 0;
	while (i < data->walls_nbs)
	{
		if (data->walls_position[i][0] == floor(x / MINI_MAP_SIZE)
			&& data->walls_position[i][1] == floor(y / MINI_MAP_SIZE))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	calculate_horizontal_intersections(t_data *data, float rounded_down_number, float rotation)
{
	if (rotation > PI)
	{
		data->ry = rounded_down_number * (MINI_MAP_SIZE) - 1;
		data->rx = (data->player.y - data->ry) * data->tan + data->player.x;
		data->yo = -MINI_MAP_SIZE;
		data->xo = -data->yo * data->tan;
		return (0);
	}
	else if (rotation < PI)
	{
		data->ry = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;
		data->rx = (data->player.y - data->ry) * data->tan + data->player.x;
		data->yo = MINI_MAP_SIZE;
		data->xo = -data->yo * data->tan;
		return (0);
	}
	if (rotation == 0 || rotation == PI)
	{
		data->rx = data->player.x;
		data->ry = data->player.y;
		return (lines_amount(data->map_array));
	}
	return (0);
}

void find_intersection_point(t_data *data, int i, float *new_x, float *new_y, int loop)
{
	while (i < loop)
	{
		if (is_wall(data, data->rx, data->ry) == 1)
		{
			*new_x = data->rx;
			*new_y = data->ry;
			break ;
		}
		else
		{
			data->rx = data->rx + data->xo;
			data->ry = data->ry + data->yo;
		}
		i++;
	}
	if (data->rx >= 600)
		data->rx = 600;
	if (data->rx <= 0)
		data->rx = 0;
	if (data->ry <= 0)
		data->ry = 0;
	if (data->ry >= 600)
		data->ry = 600;
	*new_x = data->rx;
	*new_y = data->ry;
}

void	check_intersections_h(t_data *data, float *new_x,
	float *new_y, float rotation)
{
	float	rounded_down_number;
	int		loop;
	int		i;

	i = 0;
	data->tan = -1 / tan(rotation);
	loop = lines_amount(data->map_array);
	rounded_down_number = floor(data->player.y / MINI_MAP_SIZE);
	i = calculate_horizontal_intersections(data, rounded_down_number, rotation);
	find_intersection_point(data, i, new_x , new_y, loop);
}

void	check_intersections_v(t_data *data, float *new_x,
	float *new_y, float rotation)
{
	float	rounded_down_number;
	int		loop;
	int		i;

	i = 0;
	data->tan = -tan(rotation);
	loop = biggest_line_size(data->map_array);
	rounded_down_number = floor(data->player.x / MINI_MAP_SIZE);
	if (rotation > PI / 2 && rotation < 3 * PI / 2)
	{
		data->rx = rounded_down_number * (MINI_MAP_SIZE) - 1;
		data->ry = (data->player.x - data->rx) * data->tan + data->player.y;
		data->xo = -MINI_MAP_SIZE;
		data->yo = -data->xo * data->tan;
	}
	if (rotation < PI / 2 || rotation > 3 * PI / 2)
	{
		data->rx = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;
		data->ry = (data->player.x - data->rx) * data->tan + data->player.y;
		data->xo = MINI_MAP_SIZE;
		data->yo = -data->xo * data->tan;
	}
	if (rotation == 0 || rotation == PI)
	{
		data->rx = data->player.x;
		data->ry = data->player.y;
		i = biggest_line_size(data->map_array);
	}
	while (i < loop)
	{
		if (is_wall(data, data->rx, data->ry) == 1)
		{
			*new_x = data->rx;
			*new_y = data->ry;
			break ;
		}
		else
		{
			data->rx = data->rx + data->xo;
			data->ry = data->ry + data->yo;
		}
		i++;
	}
	if (data->rx >= 600)
		data->rx = 600;
	if (data->rx <= 0)
		data->rx = 0;
	if (data->ry <= 0)
		data->ry = 0;
	if (data->ry >= 600)
		data->ry = 600;
	*new_x = data->rx;
	*new_y = data->ry;
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
		distance_horizontal = distance_btw_two_points(data->player.x,
				data->player.y, data->rays[i].h_x, data->rays[i].h_y);
		distance_vertical = distance_btw_two_points(data->player.x,
				data->player.y, data->rays[i].v_x, data->rays[i].v_y);
		if (distance_horizontal < distance_vertical + 2) //Aqui conseguimos concertar o bug baseando-se na rotação do player.
		{
			data->rays[i].x = data->rays[i].h_x;
			data->rays[i].y = data->rays[i].h_y;
			data->rays[i].distance_to_wall = distance_horizontal;
			data->rays[i].x_texture = (int)(data->rays[i].x * 4) % 64;
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
			data->rays[i].x_texture = (int)(data->rays[i].y * 4) % 64;
			if ((data->rays[i].rotation)
				< PI / 2 || data->rays[i].rotation > 3 * PI / 2)
				data->rays[i].p = 2;
			else
				data->rays[i].p = 3;
		}
		data->rays[i].diference_angle = (data->player.rotation)
			- data->rays[i].rotation;
		if (data->rays[i].diference_angle < 0)
			data->rays[i].diference_angle += 2 * PI;
		if (data->rays[i].diference_angle > 2 * PI)
			data->rays[i].diference_angle -= 2 * PI;
		data->rays[i].distance_to_wall = (data->rays[i].distance_to_wall)
			* cos(data->rays[i].diference_angle);
		data->rays[i].line_height = (MINI_MAP_SIZE * WINDOW_WIDTH) / data->rays[i].distance_to_wall;
		if (data->rays[i].line_height > WINDOW_WIDTH)
			data->rays[i].line_height = WINDOW_WIDTH;
		data->rays[i].line_o = WINDOW_HEIGHT/2 - data->rays[i].line_height/2;
		i++;
	}
}	

void	save_walls_position(t_data *data)
{
	int	i;
	int	j;
	int	z;
	int	height;
	int	width;

	height = 0;
	width = 0;
	i = 0;
	z = 0;
	while (data->map_array[i])
	{
		j = 0;
		while (data->map_array[i][j])
		{
			if (data->map_array[i][j] == '1')
			{
					data->walls_position[z][0] = width;
					data->walls_position[z][1] = height;
					z++;
			}
			width++;
			j++;
		}
		width = 0;
		height++;
		i++;
	}
}
