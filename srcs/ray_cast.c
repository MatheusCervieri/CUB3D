/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:41:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/23 16:30:38 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	The first thing in find_first_point is to see if the rotation of the player is facing up or facing down.
	We just need to find where the player is. 
*/

double	find_first_point_y()
{
	double first_y;
	int		rounded_down_number;

	rounded_down_number = floor(data->player.y / MINI_MAP_SIZE);
	if(data->player.rotation > (2 * PI)/2 && data->player.rotation < (2 * PI))
		 first_y = rounded_down_number * (MINI_MAP_SIZE) - 1;
	else
		first_y = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;


		
	return (first_y);
}



/*
	1- We find first_x with a rectus triangle formula.
	
*/
void	check_horizontal_intersections(void)
{
	double first_y;
	double first_x;
	double	diference_btw_x;
	
	first_y = find_first_point_y();
	first_x = (data->player.x - (data->player.y - first_y)/tan(data->player.rotation)); //I change the formula here, to make it works. I need to think more to use the correct formula.
	
	diference_btw_x = MINI_MAP_SIZE/tan(data->player.rotation);
	data->player.test_x = first_x;
	data->player.test_y = first_y;
	
	int i;
	i = 0;
	while (i < data->walls_nbs)
	{
		printf("X: %f\n", data->walls_position[i][0]);
		printf("Y: %f\n", data->walls_position[i][1]);
		if(data->walls_position[i][0] == floor(first_x/64) && data->walls_position[i][1] == floor(first_y/64))
			printf("É igual uhulll\n");
		i++;
	}
	printf("OUR: X: %f\n", floor(first_x/64));
	printf("OUR: Y: %f\n", floor(first_y/64));
}

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

