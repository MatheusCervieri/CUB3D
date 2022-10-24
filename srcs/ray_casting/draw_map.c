/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:48:37 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/24 18:05:35 by mvieira-         ###   ########.fr       */
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

/* I steel need to study the line algorithm */
void drawline(t_img *img, int x0, int y0, int x1, int y1, int color)
{
    int dx, dy, p, x, y;
 
dx=x1-x0;
dy=y1-y0;
 
x=x0;
y=y0;
 
p=2*dy-dx;
 
while(x<x1)
{
if(p>=0)
{

y=y+1;
p=p+2*dy-2*dx;
}
else
{
img_pix_put(img, x, y, color);
p=p+2*dy;
}
x=x+1;
}
}


void init_imgs2(t_data *data)
{
	init_img(data, &data->player.img, PLAYER_SIZE , PLAYER_SIZE);
	init_img(data, &data->player.dir_img, DIR_SIZE , DIR_SIZE);
	init_img(data, &data->test_img, DIR_SIZE , DIR_SIZE);
	init_img(data, &data->mm_wall_img, WALL_SIZE , WALL_SIZE);
}

void	render_square2(t_img *img, int color, int x, int y, int real_x, int real_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			img_pix_put(img, j++ + real_y, i + real_x, color);
		}
		++i;
	}
}


void draw_minimap(t_data *data)
{
	render_square2(&data->test_img, 0xBF40BF, DIR_SIZE, DIR_SIZE, 0 ,0);
	render_square2(&data->player.img, 0xFF00, PLAYER_SIZE, PLAYER_SIZE, 0 , 0);
	render_square2(&data->player.dir_img, 0xFF0000, DIR_SIZE, DIR_SIZE, 0 , 0);
	render_square2(&data->mm_wall_img, 000000, WALL_SIZE/4, WALL_SIZE/4, 0 , 0);
	render_square2(&data->mm_bg_img, 0xFFFFFF, BACKGROUND_SIZE, BACKGROUND_SIZE, 0, 0);
	
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->line_img.mlx_img , 0, 0);
	
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
				render_square2(&data->mm_bg_img, 000000, WALL_SIZE/4, WALL_SIZE/4, height * MINI_MAP_SIZE/4, width * MINI_MAP_SIZE/4);				
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
	//int	biggest_line_size(char **map_array)
	//int	lines_amount(char **map_array)
	i = 0;
	while (i < 320)
	{
	DDA(&data->mm_bg_img, data->player.x/4, data->player.y/4 , data->rays[i].x/4, data->rays[i].y/4, 0xFF00);
	i++;
	}
	//DDA(&data->mm_bg_img, data->player.x, data->player.y , data->player.dir_x , data->player.dir_y, 0xBF40BF);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 400);
}
