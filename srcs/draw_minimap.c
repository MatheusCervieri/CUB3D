/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:31 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/26 15:53:48 by mvieira-         ###   ########.fr       */
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
	return (data->player.rotation);
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

void init_imgs(void)
{
	init_img(&data->player.img, PLAYER_SIZE , PLAYER_SIZE);
	init_img(&data->player.dir_img, DIR_SIZE , DIR_SIZE);
	init_img(&data->test_img, DIR_SIZE , DIR_SIZE);
	init_img(&data->mm_wall_img, WALL_SIZE , WALL_SIZE);
	init_img(&data->mm_bg_img, BACKGROUND_SIZE , BACKGROUND_SIZE);
}

void draw_minimap()
{
	render_square(&data->test_img, 0xBF40BF, DIR_SIZE, DIR_SIZE);
	render_square(&data->player.img, 0xFF00, PLAYER_SIZE, PLAYER_SIZE);
	render_square(&data->player.dir_img, 0xFF0000, DIR_SIZE, DIR_SIZE);
	render_square(&data->mm_wall_img, 000000, WALL_SIZE, WALL_SIZE);
	render_square(&data->mm_bg_img, 0xFFFFFF, BACKGROUND_SIZE, BACKGROUND_SIZE);
	DDA(&data->mm_bg_img, data->player.x, data->player.y , data->rays[0].x , data->rays[0].y, 0xFF00);
	DDA(&data->mm_bg_img, data->player.x, data->player.y , data->player.dir_x , data->player.dir_y, 0xBF40BF);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 0);
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
