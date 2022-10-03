/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:41:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/03 15:35:16 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_horizontal_wall(double x, double y)
{
	int i;
	i = 0;
	while (i < data->walls_nbs)
	{
		if(data->walls_position[i][0] == floor(x/MINI_MAP_SIZE) && data->walls_position[i][1] == floor(y/MINI_MAP_SIZE))
		{
			return(1);
		}
		/*
		if(data->walls_position[i][0] + 1 == x/MINI_MAP_SIZE && data->walls_position[i][1] == floor(y/MINI_MAP_SIZE))
		{
			return(1);
		} 
		if(data->walls_position[i][0] == floor(x/MINI_MAP_SIZE) && data->walls_position[i][1] + 1 == y/MINI_MAP_SIZE)
		{
			return(1);
		}
		if(data->walls_position[i][0] + 1 == x/MINI_MAP_SIZE && data->walls_position[i][1] + 1 == y/MINI_MAP_SIZE)
		{
			return(1);
		}
		*/	
		i++;
	}
	return (0);
}


void check_intersections_2(double *new_x, double *new_y, double rotation)
{
	float		rounded_down_number;
	int			loop;
	int			i = 0;
	data->tan = -1/tan(rotation);
	loop = lines_amount(data->map_array);
	rounded_down_number = floor(data->player.y / MINI_MAP_SIZE);
	if (rotation > PI)
	{
		data->ry = rounded_down_number * (MINI_MAP_SIZE) - 1;
		data->rx = (data->player.y - data->ry) * data->tan + data->player.x; 
		data->yo = - MINI_MAP_SIZE;
		data->xo = -data->yo * data->tan;
	}
	else if (rotation < PI)
	{ 
		data->ry = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;
		data->rx = (data->player.y - data->ry) * data->tan + data->player.x; 
		data->yo = MINI_MAP_SIZE;
		data->xo = -data->yo * data->tan;
	}
	if(rotation == 0 || rotation == PI)
	{
		data->rx=data->player.x;
		data->ry=data->player.y;
		i = lines_amount(data->map_array);
	}
	while (i < loop)
	{
			
		if(is_horizontal_wall(data->rx, data->ry) == 1)
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

void check_intersections_2_vertical(double *new_x, double *new_y, double rotation)
{
	data->tan = -tan(rotation);
	float		rounded_down_number;
	int			loop;
	int			i = 0;
	loop = biggest_line_size(data->map_array);
	rounded_down_number = floor(data->player.x / MINI_MAP_SIZE);
	if (rotation > PI/2 && rotation < 3*PI/2)
	{
		data->rx =  rounded_down_number * (MINI_MAP_SIZE) - 1;
		data->ry = (data->player.x - data->rx) * data->tan + data->player.y; 
		data->xo = - MINI_MAP_SIZE;
		data->yo = -data->xo * data->tan;
	}
	if (rotation < PI/2 || rotation > 3*PI/2)
	{ 
		data->rx = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;
		data->ry = (data->player.x - data->rx) * data->tan + data->player.y; 
		data->xo = MINI_MAP_SIZE;
		data->yo = -data->xo * data->tan;
	}
	if(rotation == 0 || rotation == PI)
	{
		data->rx=data->player.x;
		data->ry= data->player.y;
		i = biggest_line_size(data->map_array);
	}
	while (i < loop)
	{
			
		if(is_horizontal_wall(data->rx, data->ry) == 1)
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


void check_intersections(void)
{
	double distance_horizontal;
	double distance_vertical;
	double ray_angle;
	int		i;
	//Se os dois tem intersection, a intersection correta é o do ponto que está mais perto. 
	//check_horizontal_intersections(&data->rays[0].x, &data->rays[0].y , data->rays[0].rotation);
	i = 0;
	while (i < 320)
	{
	data->rays[i].rotation = data->player.rotation - 30*DG + (DG*60/320)*i;
	if(data->rays[i].rotation < 0)
		data->rays[i].rotation+= 2*PI;
	if(data->rays[i].rotation > 2*PI)
		data->rays[i].rotation-=2*PI;
	check_intersections_2(&data->rays[i].h_x, &data->rays[i].h_y , data->rays[i].rotation);
	check_intersections_2_vertical(&data->rays[i].v_x, &data->rays[i].v_y , data->rays[i].rotation);	
	distance_horizontal = distance_btw_two_points(data->player.x, data->player.y, data->rays[i].h_x, data->rays[i].h_y);
	distance_vertical = distance_btw_two_points(data->player.x, data->player.y, data->rays[i].v_x, data->rays[i].v_y);
	if (distance_horizontal <= distance_vertical)
	{
		data->rays[i].x = data->rays[i].h_x;
		data->rays[i].y = data->rays[i].h_y;
		data->rays[i].distance_to_wall = distance_horizontal;
		data->rays[i].x_texture = (int)(data->rays[i].x*4) % 64;  //Multiplicamos por 2 porque o nosso minimap é 16; 32 é o tamanho da textura. 
		if(data->rays[i].rotation > 0 && data->rays[i].rotation < PI)
			data->rays[i].position = 1; //Horizontal cima. 
		else
			data->rays[i].position = 0;
			 //Horizontal baixo. 
	}
	else
	{
		data->rays[i].x = data->rays[i].v_x;
		data->rays[i].y = data->rays[i].v_y;
		data->rays[i].distance_to_wall = distance_vertical;
		data->rays[i].x_texture = (int)(data->rays[i].y*4) % 64;  //Multiplicamos por 2 porque o nosso minimap é 16; 32 é o tamanho da textura. 
		if(data->rays[i].rotation < PI/2 || data->rays[i].rotation > 3*PI/2)
			data->rays[i].position = 2; //vertical direita. 
		else
			data->rays[i].position = 3; //Vertical esquerda. 

	}
	//Projected Slice Height = 64 / Distance to the Slice * 277 (Part 5);
	//data->rays[i].line_height = MINI_MAP_SIZE / (data->rays[i].distance_to_wall * (WINDOW_WIDTH/2)/tan(DG*30)); 
	
	//data->rays[i].line_o = WINDOW_HEIGHT/2 - data->rays[i].line_height/2;
	//diference entre player angle and ray angle;
	data->rays[i].diference_angle = data->player.rotation - data->rays[i].rotation;
	if(data->rays[i].diference_angle < 0)
		data->rays[i].diference_angle+= 2*PI;
	if(data->rays[i].diference_angle > 2*PI)
		data->rays[i].diference_angle-=2*PI;
	data->rays[i].distance_to_wall = data->rays[i].distance_to_wall * cos(data->rays[i].diference_angle);
	data->rays[i].line_height = (MINI_MAP_SIZE * WINDOW_WIDTH)/data->rays[i].distance_to_wall;
	if(data->rays[i].line_height > WINDOW_WIDTH)
		data->rays[i].line_height = WINDOW_WIDTH;
	data->rays[i].line_o = WINDOW_HEIGHT/2 - data->rays[i].line_height/2;
	
	i++;
	}
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

