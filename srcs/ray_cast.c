/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:41:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/29 20:05:15 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	The first thing in find_first_point is to see if the rotation of the player is facing up or facing down.
	We just need to find where the player is. 
*/

double	find_first_point_y(double ray_rotation)
{
	double first_y;
	float		rounded_down_number;

	rounded_down_number = floor(data->player.y / MINI_MAP_SIZE);
	if(ray_rotation > PI)
	{
		 first_y = rounded_down_number * (MINI_MAP_SIZE) - 1;
	}
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
			return(1);
		} 
			
		i++;
	}
	return (0);
}

void check_intersections_2(double *new_x, double *new_y, double rotation)
{
	float ray_rotation;
	ray_rotation = rotation;
	float aTan = -1/tan(ray_rotation);
	float ry;
	float rx;
	float yo;
	float xo;
	float		rounded_down_number;
	int			loop;
	int			i = 0;
	loop = lines_amount(data->map_array);
	rounded_down_number = floor(data->player.y / MINI_MAP_SIZE);
	if (ray_rotation > PI)
	{
		ry = rounded_down_number * (MINI_MAP_SIZE) - 1;
		rx = (data->player.y - ry) * aTan + data->player.x; 
		yo = - MINI_MAP_SIZE;
		xo = -yo * aTan;
	}
	else if (ray_rotation < PI)
	{ 
		ry = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;
		rx = (data->player.y - ry) * aTan + data->player.x; 
		yo = MINI_MAP_SIZE;
		xo = -yo * aTan;
	}
	if(ray_rotation == 0 || ray_rotation == PI)
	{
		rx=data->player.x;
		ry= data->player.y;
		i = lines_amount(data->map_array);
	}
	while (i < loop)
	{
			
		if(is_horizontal_wall(rx, ry) == 1)
		{
			*new_x = rx;
			*new_y = ry;
			break ;
		}
		else
		{
			rx = rx + xo;
			ry = ry + yo;
		}
		i++;
	}
	if (rx >= 600)
		rx = 600;
	if (rx <= 0)
		rx = 0;
	if (ry <= 0)
		ry = 0;	
	if (ry >= 600)
		ry = 600;
	*new_x = rx;
	*new_y = ry;
}

void check_intersections_2_vertical(double *new_x, double *new_y, double rotation)
{
	float ray_rotation;
	ray_rotation = rotation;
	float aTan = -tan(ray_rotation);
	float ry;
	float rx;
	float yo;
	float xo;
	float		rounded_down_number;
	int			loop;
	int			i = 0;
	loop = biggest_line_size(data->map_array);
	rounded_down_number = floor(data->player.x / MINI_MAP_SIZE);
	if (ray_rotation > PI/2 && ray_rotation < 3*PI/2)
	{
		rx =  rounded_down_number * (MINI_MAP_SIZE) - 1;
		ry = (data->player.x - rx) * aTan + data->player.y; 
		xo = - MINI_MAP_SIZE;
		yo = -xo * aTan;
	}
	if (ray_rotation < PI/2 || ray_rotation > 3*PI/2)
	{ 
		rx = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;
		ry = (data->player.x - rx) * aTan + data->player.y; 
		xo = MINI_MAP_SIZE;
		yo = -xo * aTan;
	}
	if(ray_rotation == 0 || ray_rotation == PI)
	{
		rx=data->player.x;
		ry= data->player.y;
		i = biggest_line_size(data->map_array);
	}
	while (i < loop)
	{
			
		if(is_horizontal_wall(rx, ry) == 1)
		{
			*new_x = rx;
			*new_y = ry;
			break ;
		}
		else
		{
			rx = rx + xo;
			ry = ry + yo;
		}
		i++;
	}
	if (rx >= 600)
		rx = 600;
	if (rx <= 0)
		rx = 0;
	if (ry <= 0)
		ry = 0;	
	if (ry >= 600)
		ry = 600;
	*new_x = rx;
	*new_y = ry;
}

/*
	1- We find first_x with a rectus triangle formula.
	
*/
int	check_horizontal_intersections(double *new_x, double *new_y, double rotation)
{
	double first_y;
	double first_x;
	double	diference_btw_x;
	double ray_rotation;
	ray_rotation = rotation + data->player.rotation;
	//Checar se passa de 2pi ou não. 
	first_y = find_first_point_y(ray_rotation);
	printf("----------------------------\n");
	printf("Rotation ray: %f \n", rotation);
	printf("Rotation player: %f \n", data->player.rotation);
	printf("Data Player x: %f\n", data->player.x);
	printf("Data Player y: %f \n", data->player.y);
	//if(ray_rotation >= 0.1 && ray_rotation <= 0.2)
		//ray_rotation = 0.2; //I need to undesetand thist. 
	first_x = (data->player.x + (data->player.y - first_y)/tan(ray_rotation)); //Se passar substituir o valor. 
	
	printf("First x: %f\n", first_x);
	printf("First y: %f\n", first_y);
	printf("Tan rotation %f\n", tan(ray_rotation));
	diference_btw_x = MINI_MAP_SIZE/tan(ray_rotation);
	int i;

	i = 0;
	int horizontal_lines = lines_amount(data->map_array);


	while(i < horizontal_lines)
	{

		if(is_horizontal_wall(first_x, first_y) == 1)
		{
			printf("Is wall \n");
			printf("Rotation: %f\n", ray_rotation);
			printf("OUR: X: %f\n", floor(first_x));
			printf("OUR: Y: %f\n", floor(first_y));
			*new_x = first_x;
			*new_y = first_y;
			return(1);
		}
		//first_x = first_x - diference_btw_x;
		if(ray_rotation > PI)
		{
			first_x = first_x - diference_btw_x;
			first_y = first_y - MINI_MAP_SIZE;
		}
		else
		{
			first_x = first_x + diference_btw_x;
			first_y = first_y + MINI_MAP_SIZE;
		}
		
		i++;
	}


	return (0);
	
}
//Quarto quadrante: 3π/2 < x < 2π

double	find_first_point_x(double ray_rotation)
{
	double first_x;
	int		rounded_down_number;

	rounded_down_number = floor(data->player.x / MINI_MAP_SIZE);
	if(sin(ray_rotation) > 0.001 )
		first_x = rounded_down_number * (MINI_MAP_SIZE) + MINI_MAP_SIZE;
	else if(sin(ray_rotation) < -0.001)
		first_x = rounded_down_number * (MINI_MAP_SIZE) - 1;
	return (first_x);
}

int	check_vertical_intersections(double *new_x, double *new_y, double rotation)
{
	double first_y;
	double first_x;
	double	diference_btw_y;
	float ray_rotation;
	int vertical_lines;
	ray_rotation = rotation + data->player.rotation;



	first_x = find_first_point_x(ray_rotation);
	//A.y = Py + (Px-A.x)*tan(ALPHA);
	first_y = ((data->player.x - first_x) * tan(ray_rotation)) + data->player.y ;
	diference_btw_y = MINI_MAP_SIZE * tan(ray_rotation);
	if(first_x == data->player.x)
		first_y = data->player.y;
	

	
	if(sin(ray_rotation) > 0.001 )
	{
		first_y = first_y + diference_btw_y;
		first_x = first_x + MINI_MAP_SIZE;
	}
	else
	{
		first_y = first_y - diference_btw_y;
		first_x = first_x - MINI_MAP_SIZE;
	}
	
		
	if(sin(ray_rotation) > 0.001 )
	{
		first_y = first_y + diference_btw_y;
		first_x = first_x + MINI_MAP_SIZE;
	}
	else
	{
		first_y = first_y - diference_btw_y;
		first_x = first_x - MINI_MAP_SIZE;
	}
	

	if(first_x == data->player.x)
	{
		
	}
	else
	{	
	*new_x = first_x;
	*new_y = first_y;
	}
	/*
	int i;

	i = 0;

	vertical_lines = biggest_line_size(data->map_array);
	while(i < vertical_lines)
	{

		if(is_horizontal_wall(first_x, first_y) == 1)
		{
			*new_x = first_x;
			*new_y = first_y;
			return(1);
		}
		first_y = first_y + diference_btw_y;
		if( sin(ray_rotation) > 0.001 )
			first_x = first_x - MINI_MAP_SIZE;
		else
			first_x = first_x + MINI_MAP_SIZE;
		i++;
	}
*/
	return (0);
	
}





/*
Aqui no vertical interesections eu mudei o angulo para se adequar ao circulo vertical, entretanto seria mais interessante 
receber o rotation e mudar ele aqui acrescentando PI ao valor, dessa forma tanto a checagem vertical quando horizontal estão
corretas
*/
/*
int	check_vertical_intersections(void)
{
	double first_y;
	double first_x;
	double	diference_btw_y;
	
	first_x = find_first_point_x();
	//A.y = Py + (Px-A.x)*tan(ALPHA)
	first_y = (data->player.y + (data->player.x - first_x)/tan(data->player.rotation)); //I change the formula here, to make it works. I need to think more to use the correct formula.
	
	diference_btw_y = MINI_MAP_SIZE * tan(data->player.rotation);
	int i;
	i = 0;
	int vertical_lines = biggest_line_size(data->map_array);

	
	while(i < vertical_lines)
	{
		if(is_horizontal_wall(first_x, first_y) == 1)
		{
				printf("There is a wall \n");
	printf("OUR: X: %f\n", floor(first_x));
	printf("OUR: Y: %f\n", floor(first_y));
			data->player.test_x = first_x;
			data->player.test_y = first_y;
			return (1);
		}
		
		//if(data->player.rotation > (3 * PI) / 2 && data->player.rotation < (2 * PI) || data->player.rotation > 0 && data->player.rotation < (PI)/2 ) //facing right.
		if( data->player.rotation > (PI)/2 && data->player.rotation < PI  || data->player.rotation > 0 && data->player.rotation < (PI)/2 ) //facing right.
		{
			
			first_x = first_x + MINI_MAP_SIZE;
		}
		else
		{
			first_x = first_x - MINI_MAP_SIZE;
		}
	
		i++;
	}
	printf("There is no wall \n");
	printf("OUR: X: %f\n", floor(first_x));
	printf("OUR: Y: %f\n", floor(first_y));
	//printf("OUR: X: %f\n", floor(first_x/64));
	//printf("OUR: Y: %f\n", floor(first_y/64));
	return (0);
}
*/
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
	}
	else
	{
		data->rays[i].x = data->rays[i].v_x;
		data->rays[i].y = data->rays[i].v_y;
		data->rays[i].distance_to_wall = distance_vertical;
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

