/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:02:12 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/11 04:31:12 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int abs(int n) { return ((n > 0) ? n : (n * (-1))); }
 
// DDA Function for line generation
void DDA(t_img *img, int X0, int Y0, int X1, int Y1, int color)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
    	 img_pix_put(img, X, Y, color); // put pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
    }
}

void init_minimap_imgs(t_data *data)
{
	//init_img(data, &data->game_img, WINDOW_WIDTH , WINDOW_HEIGHT); // Quando for fazer a versão definitiva, comentar a parte de baixo.
	//init_img(data, &data->mm_bg_img, BACKGROUND_SIZE , BACKGROUND_SIZE);
	init_img(data, &data->player.img, PLAYER_SIZE/4 , PLAYER_SIZE/4);
	init_img(data, &data->player.dir_img, DIR_SIZE/4 , DIR_SIZE/4);
	init_img(data, &data->test_img, DIR_SIZE/4 , DIR_SIZE/4);
	init_img(data, &data->mm_wall_img, WALL_SIZE/4 , WALL_SIZE/4);
	
}

void draw_minimap(t_data *data)
{
	render_square(&data->test_img, 0xBF40BF, DIR_SIZE/4, DIR_SIZE/4, 0 ,0);
	render_square(&data->player.img, 0xFF00, PLAYER_SIZE/4, PLAYER_SIZE/4, 0 , 0);
	render_square(&data->player.dir_img, 0xFF0000, DIR_SIZE/4, DIR_SIZE/4, 0 , 0);
	render_square(&data->mm_wall_img, 000000, WALL_SIZE/4, WALL_SIZE/4, 0 , 0);
	render_square(&data->mm_bg_img, 0xFFFFFF, BACKGROUND_SIZE, BACKGROUND_SIZE, 0, 0);
	
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
				render_square(&data->mm_bg_img, 000000, WALL_SIZE/4, WALL_SIZE/4, height * MINI_MAP_SIZE/4, width * MINI_MAP_SIZE/4);
				
			}
			width++;
			j++;
		}
		width = 0;
		height++;
		i++;
	}
	
	i = 0;
	while (i < lines_amount(data->map_array))
	{
		DDA(&data->mm_bg_img, 0, MINI_MAP_SIZE/4 * i , 600 , MINI_MAP_SIZE/4 * i, 000003);
		i++;
	}
	
	i = 0;
	while (i < biggest_line_size(data->map_array))
	{
		DDA(&data->mm_bg_img, MINI_MAP_SIZE/4 * i, 0 , MINI_MAP_SIZE/4 * i , 600, 000003);
		i++;
	}
	
	i = 0;
	while (i < 320)
	{
	DDA(&data->mm_bg_img, data->player.x/4, data->player.y/4 , data->rays[i].x/4, data->rays[i].y/4, 0xFF00);
	i++;
	}
	
	DDA(&data->mm_bg_img, data->player.x, data->player.y , data->player.dir_x , data->player.dir_y, 0xBF40BF);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 0);
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->player.img.mlx_img, data->player.x, data->player.y);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->game_img.mlx_img, 0, 400);
}