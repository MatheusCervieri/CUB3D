/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:08:18 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 21:08:44 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_positions(t_data *data, int height, int width, int *z)
{
		data->walls_position[*z][0] = width;
		data->walls_position[*z][1] = height;
		*z = *z + 1;
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
				set_wall_positions(data, height, width, &z);
			width++;
			j++;
		}
		width = 0;
		height++;
		i++;
	}
}
