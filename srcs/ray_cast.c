/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:41:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/22 23:04:02 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_walls_position(void)
{
	int i;
	int j;
	int z;
	int height;
	int width;

	height = 0; 
	width = 0;
	i = 0;
	z = 0;
	while (data->map_array[i])
	{
		j = 0;
		while (data->map_array[i][j])
		{
			if(data->map_array[i][j] == '1')
			{
					data->walls_position[z][0] = width * MINI_MAP_SIZE;
					data->walls_position[z][1] = height * MINI_MAP_SIZE;
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

