/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:49:02 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/05 15:42:02 by mvieira-         ###   ########.fr       */
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
