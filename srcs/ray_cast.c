/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:41:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/23 21:29:59 by mvieira-         ###   ########.fr       */
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

int	is_horizontal_wall(double x, double y)
{
	int i;
	i = 0;
	while (i < data->walls_nbs)
	{
		if(data->walls_position[i][0] == floor(x/MINI_MAP_SIZE) && data->walls_position[i][1] == floor(y/MINI_MAP_SIZE))
		{
			printf("É igual uhulll %i\n", i);
			return(1);
		} 
			
		i++;
	}
	return (0);
}

/*
	1- We find first_x with a rectus triangle formula.
	
*/
int	check_horizontal_intersections(void)
{
	double first_y;
	double first_x;
	double	diference_btw_x;
	
	first_y = find_first_point_y();
	first_x = (data->player.x + (data->player.y - first_y)/tan(data->player.rotation)); //I change the formula here, to make it works. I need to think more to use the correct formula.
	
	diference_btw_x = MINI_MAP_SIZE/tan(data->player.rotation);

	int i;

	i = 0;
	int horizontal_lines = lines_amount(data->map_array);
	while(i < horizontal_lines)
	{
		if(is_horizontal_wall(first_x, first_y) == 1)
		{
			data->player.test_x = first_x;
			data->player.test_y = first_y;
			return(1);
		}
		first_x = first_x + diference_btw_x;
		if(data->player.rotation > (2 * PI)/2 && data->player.rotation < (2 * PI))
			first_y = first_y - MINI_MAP_SIZE;
		else
			first_y = first_y + MINI_MAP_SIZE;
		i++;
	}
	return (0);
	//printf("OUR: X: %f\n", floor(first_x/64));
	//printf("OUR: Y: %f\n", floor(first_y/64));
}
//Quarto quadrante: 3π/2 < x < 2π

double	find_first_point_x()
{
	double first_x;
	int		rounded_down_number;

	rounded_down_number = floor(data->player.x / MINI_MAP_SIZE);
	if(data->player.rotation > (3 * PI) / 2 && data->player.rotation < (2 * PI) || data->player.rotation > 0 && data->player.rotation < (PI)/2 ) //facing right.
		first_x = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;
	else
		first_x = rounded_down_number * (MINI_MAP_SIZE) - 1;
	return (first_x);
}


void	check_vertical_intersections(void)
{
	double first_y;
	double first_x;
	double	diference_btw_y;
	
	first_x = find_first_point_x();
	//A.y = Py + (Px-A.x)*tan(ALPHA)
	first_y = (data->player.y + (data->player.x - first_x)/tan(data->player.rotation)); //I change the formula here, to make it works. I need to think more to use the correct formula.
	
	diference_btw_y = MINI_MAP_SIZE/tan(data->player.rotation);
	int i;
	i = 0;
	int vertical_lines = biggest_line_size(data->map_array);
	printf("OUR: X: %f\n", floor(first_x));
	printf("OUR: Y: %f\n", floor(first_y));
	
	while(i < vertical_lines)
	{
		if(is_horizontal_wall(first_x, first_y) == 1)
		{
		
			data->player.test_x = first_x;
			data->player.test_y = first_y;
			break ;
		}
		first_y = first_y + diference_btw_y;
		if(data->player.rotation > (3 * PI) / 2 && data->player.rotation < (2 * PI) || data->player.rotation > 0 && data->player.rotation < (PI)/2 ) //facing right.
			first_x = first_x + MINI_MAP_SIZE;
		else
			first_x = first_x - MINI_MAP_SIZE;
		i++;
	}
	//printf("OUR: X: %f\n", floor(first_x/64));
	//printf("OUR: Y: %f\n", floor(first_y/64));
}

void check_intersections(void)
{
	//Se os dois tem intersection, a intersection correta é o do ponto que está mais perto. 
	check_horizontal_intersections();
	check_vertical_intersections();
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

