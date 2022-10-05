/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:31 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/05 11:56:14 by mvieira-         ###   ########.fr       */
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

int	img_pix_get(t_img *img, int x, int y)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return(*(int *)pixel);
}

float distance_btw_two_points(float x1, float y1, float x2, float y2) 
{
	float distance;
	
	distance = ((x2 - x1) * (x2-x1)) + ((y2-y1) * (y2-y1));
	
	return (sqrt(distance));
}

float rotate_player_dir(t_data * data, float speed, float *x, float *y, float *t)
{
	float radius = distance_btw_two_points(*x, *y, data->player.x, data->player.y);
	*x = radius*cos(*t) + data->player.x;
	*y = radius*sin(*t) + data->player.y;
	data->player.rotation = data->player.rotation + speed;
	return (data->player.rotation);
}

void init_img(t_data *data, t_img *img, int height, int width)
{
	img->mlx_img = mlx_new_image(data->mlx, height, width);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
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


void init_imgs(t_data *data)
{
	init_img(data, &data->game_img, WINDOW_WIDTH , WINDOW_HEIGHT); // Quando for fazer a versão definitiva, comentar a parte de baixo.
	init_img(data, &data->mm_bg_img, BACKGROUND_SIZE , BACKGROUND_SIZE);
	render_square(&data->mm_bg_img, 0xFFFFFF, BACKGROUND_SIZE, BACKGROUND_SIZE, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 0);
	/*
	init_img(data, &data->player.img, PLAYER_SIZE , PLAYER_SIZE);
	init_img(data, &data->player.dir_img, DIR_SIZE , DIR_SIZE);
	init_img(data, &data->test_img, DIR_SIZE , DIR_SIZE);
	init_img(data, &data->mm_wall_img, WALL_SIZE , WALL_SIZE);
	*/
	
}

void draw_3d_world(t_data *data)
{
	int	i;
	int j;
	float y_texture;
	float y_texture_step;

	render_square(&data->game_img, *data->ceiling_color, WINDOW_WIDTH, WINDOW_HEIGHT, 0 , 0);	
	render_square(&data->game_img, *data->floor_color, WINDOW_WIDTH, WINDOW_HEIGHT/2, 0 , 0);	
	i = 0;
	while (i < 320)
	{
		y_texture = 0;
		y_texture_step = 64/(float)data->rays[i].line_height; //32 é o tamanho da textura
		j = 0;
		while(j < data->rays[i].line_height)
		{
			data->rays[i].pixel = img_pix_get(&data->texture_img[data->rays[i].position], (int) data->rays[i].x_texture , (int)y_texture);
			img_pix_put(&data->game_img, 0 + i, j + data->rays[i].line_o, data->rays[i].pixel);
			y_texture+= y_texture_step; 
			j++;
		}
	i++;
	}
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->game_img.mlx_img , 0, 0);
}

void draw(t_data *data)
{
	//draw_minimap(data);
	draw_3d_world(data);
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->game_img.mlx_img , 0, 300);
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->texture_img[0].mlx_img , 0, 0);
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->texture_img[1].mlx_img , 64, 0);
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->texture_img[2].mlx_img , 128, 0);
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->texture_img[3].mlx_img , 196, 0);
}

/*
void draw_minimap(t_data *data)
{
	render_square(&data->test_img, 0xBF40BF, DIR_SIZE, DIR_SIZE, 0 ,0);
	render_square(&data->player.img, 0xFF00, PLAYER_SIZE, PLAYER_SIZE, 0 , 0);
	render_square(&data->player.dir_img, 0xFF0000, DIR_SIZE, DIR_SIZE, 0 , 0);
	render_square(&data->mm_wall_img, 000000, WALL_SIZE, WALL_SIZE, 0 , 0);
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
				render_square(&data->mm_bg_img, 000000, WALL_SIZE, WALL_SIZE, height * MINI_MAP_SIZE, width * MINI_MAP_SIZE);
				
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
		DDA(&data->mm_bg_img, 0, MINI_MAP_SIZE * i , 600 , MINI_MAP_SIZE * i, 000003);
		i++;
	}
	
	i = 0;
	while (i < biggest_line_size(data->map_array))
	{
		DDA(&data->mm_bg_img, MINI_MAP_SIZE * i, 0 , MINI_MAP_SIZE * i , 600, 000003);
		i++;
	}
	
	i = 0;
	while (i < 320)
	{
	DDA(&data->mm_bg_img, data->player.x, data->player.y , data->rays[i].x, data->rays[i].y, 0xFF00);
	i++;
	}
	
	DDA(&data->mm_bg_img, data->player.x, data->player.y , data->player.dir_x , data->player.dir_y, 0xBF40BF);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 0);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->player.img.mlx_img, data->player.x, data->player.y);
}
*/