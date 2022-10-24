/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:39:00 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/24 16:22:09 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calculate_horizontal_intersections(t_data *data,
	float rounded_down_number, float rotation)
{
	(void)rounded_down_number;
	if (rotation > PI)
	{
		data->ry = (((int)data->player.y >> 6) << 6) - 0.0001;
		data->rx = (data->player.y - data->ry) * data->tan + data->player.x;
		data->yo = -MINI_MAP_SIZE;
		data->xo = -data->yo * data->tan;
		return (0);
	}
	else if (rotation < PI)
	{
		data->ry = (((int)data->player.y >> 6) << 6) + 64;
		data->rx = (data->player.y - data->ry) * data->tan + data->player.x;
		data->yo = MINI_MAP_SIZE;
		data->xo = -data->yo * data->tan;
		return (0);
	}
	return (0);
}

void	check_intersections_h(t_data *data, float *new_x,
	float *new_y, float rotation)
{
	float	rounded_down_number;
	int		loop;

	data->tan = -1 / tan(rotation);
	loop = lines_amount(data->map_array);
	rounded_down_number = floor(data->player.y / MINI_MAP_SIZE);
	calculate_horizontal_intersections(data, rounded_down_number, rotation);
	find_intersection_point_h(data, new_x, new_y, loop);
}

int	calculate_vertical_intersections(t_data *data,
	float rounded_down_number, float rotation)
{
	(void)rounded_down_number;
	if (rotation > PI / 2 && rotation < 3 * PI / 2)
	{
		data->rx = (((int)data->player.x >> 6) << 6) - 0.0001;
		data->ry = (data->player.x - data->rx) * data->tan + data->player.y;
		data->xo = -MINI_MAP_SIZE;
		data->yo = -data->xo * data->tan;
		return (0);
	}
	if (rotation < PI / 2 || rotation > 3 * PI / 2)
	{
		data->rx = (((int)data->player.x >> 6) << 6) + 64;
		data->ry = (data->player.x - data->rx) * data->tan + data->player.y;
		data->xo = MINI_MAP_SIZE;
		data->yo = -data->xo * data->tan;
		return (0);
	}
	return (0);
}

void	check_intersections_v(t_data *data, float *new_x,
	float *new_y, float rotation)
{
	float	rounded_down_number;
	int		loop;

	data->tan = -tan(rotation);
	loop = biggest_line_size(data->map_array);
	rounded_down_number = floor(data->player.x / MINI_MAP_SIZE);
	calculate_vertical_intersections(data, rounded_down_number, rotation);
	find_intersection_point_v(data, new_x, new_y, loop);
}
