/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:31 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/23 17:57:36 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define PLAYER_SIZE 16
# define BACKGROUND_SIZE 600
# define WALL_SIZE 16
# define DIR_SIZE 8

//Pegar a quantidade de walls.
//Salvar os pontos que tem walls. 
//Checar as intercecções horizontais. 

double distance_btw_two_points(float x1, float y1, float x2, float y2) 
{
	double distance;
	
	distance = ((x2 - x1) * (x2-x1)) + ((y2-y1) * (y2-y1));
	
	return (sqrt(distance));
}

double rotate_player_dir(double speed, double *x, double *y, double *t)
{
	double radius = distance_btw_two_points(*x, *y, data->player.x, data->player.y);
	*x = radius*cos(*t) + data->player.x;
	*y = radius*sin(*t) + data->player.y;
	data->player.rotation = data->player.rotation + speed;
}

void init_img(t_img *img, int height, int width)
{
	img->mlx_img = mlx_new_image(data->mlx, height, width);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
}

void draw_player_mini_map()
{
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->player.img.mlx_img, data->player.x, data->player.y);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->player.dir_img.mlx_img, data->player.dir_x, data->player.dir_y);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->test_img.mlx_img , data->player.test_x, data->player.test_y);
}

void draw_minimap()
{
	init_img(&data->player.img, PLAYER_SIZE , PLAYER_SIZE);
	init_img(&data->player.dir_img, DIR_SIZE , DIR_SIZE);
	init_img(&data->test_img, DIR_SIZE , DIR_SIZE);
	init_img(&data->mm_wall_img, WALL_SIZE , WALL_SIZE);
	init_img(&data->mm_bg_img, BACKGROUND_SIZE , BACKGROUND_SIZE);
	render_square(&data->test_img, 0xBF40BF, DIR_SIZE, DIR_SIZE);
	render_square(&data->player.img, 0xFF00, PLAYER_SIZE, PLAYER_SIZE);
	render_square(&data->player.dir_img, 0xFF0000, DIR_SIZE, DIR_SIZE);
	render_square(&data->mm_wall_img, 000000, WALL_SIZE, WALL_SIZE);
	render_square(&data->mm_bg_img, 0xFFFFFF, BACKGROUND_SIZE, BACKGROUND_SIZE);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 0);
	
	
	
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_wall_img.mlx_img , 0, 0);
	int i;
	int j;
	int height;
	int width;

	height = 0; 
	width = 0;
	i = 0;
	while (data->map_array[i])
	{
		j = 0;
		while (data->map_array[i][j])
		{
			if(data->map_array[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_wall_img.mlx_img , width * MINI_MAP_SIZE, height * MINI_MAP_SIZE);
			}
			width++;
			j++;
		}
		width = 0;
		height++;
		i++;
	}
	draw_player_mini_map();
}
