/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:49:02 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/24 20:12:04 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall_h(t_data *data, float x, float y)
{
	int	i;

	int mx;
	int my;
	mx=(int)(x) >> 6;
	
	my=(int)(y) >> 6;
	i = 0;
	while (i < data->walls_nbs)
	{
		if (data->walls_position[i][0] == mx && data->walls_position[i][1] == my)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_wall_v(t_data *data, float x, float y)
{
	int	i;
	int mx;
	int my;
	mx=(int)(x)>>6; my=(int)(y)>>6;
	i = 0;
	while (i < data->walls_nbs)
	{
		if (data->walls_position[i][0] == mx
			&& data->walls_position[i][1] == my)
			return (1);
		i++;
	}
	return (0);
}

void	find_intersection_point_h(t_data *data,
	float *new_x, float *new_y, int loop)
{
	int	i;

	i = -1;
	while (i++ < loop)
	{
		if (is_wall_h(data, data->rx, data->ry) == 1)
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
	}
	*new_x = data->rx;
	*new_y = data->ry;
}

void	find_intersection_point_v(t_data *data,
	float *new_x, float *new_y, int loop)
{
	int	i;

	i = -1;
	while (i++ < loop)
	{
		if (is_wall_v(data, data->rx, data->ry) == 1)
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
	}
	*new_x = data->rx;
	*new_y = data->ry;
}
