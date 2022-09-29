/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:31 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/29 15:08:05 by mvieira-         ###   ########.fr       */
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

void init_textures(t_img *img, int height, int width, char *dir)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx, dir, &width, &height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	printf("Width %i", width);
}

void init_imgs(void)
{
	init_img(&data->player.img, PLAYER_SIZE , PLAYER_SIZE);
	init_img(&data->game_img, WINDOW_WIDTH , WINDOW_HEIGHT);
	init_img(&data->player.dir_img, DIR_SIZE , DIR_SIZE);
	init_img(&data->test_img, DIR_SIZE , DIR_SIZE);
	init_img(&data->mm_wall_img, WALL_SIZE , WALL_SIZE);
	init_img(&data->mm_bg_img, BACKGROUND_SIZE , BACKGROUND_SIZE);
	int width = 64;
	int height = 64;
	init_textures(&data->texture_img, 64 , 64, "texture.xpm");
	printf("%i\n", width);
	printf("%i\n", height);
}

void manipulate_img()
{
	int *data2; 
	int count_h;
	int count_w;
		count_h = -1;
	data2 = (int *)data->texture_img.addr;
	int i = 0;
	printf("Line len%d\n", data->texture_img.line_len);
	printf("BPP %d\n", data->texture_img.bpp);
	printf("endian %d\n", data->texture_img.bpp);
	//int pos = (y * size_line + x * (bits_per_pixel / 8));
	//int pos = (y * data->texture_img.line_len + x * (data->texture_img.bpp / 8));
	//index = line_len * y + x * (bpp / 8)
	int pos = (2 * data->texture_img.line_len + 15 * (data->texture_img.bpp / 8));
	data2[pos] = 0xBF40BF;
	data2[pos + 1] = 0xBF40BF;
	data2[pos + 2] = 0xBF40BF;
	data2[pos + 3] = 0xBF40BF;
	data2[pos + 4] = 0xBF40BF;
	data2[pos + 5] = 0xBF40BF;
	data2[pos + 6] = 0xBF40BF;
	/*
	while (i < 32)
	{
		data2[i] = 0xBF40BF;
		i++;
	}
	*/
	DDA(&data->mm_bg_img, 0 , 0, 100, 100, data2[500]);
	
	/*
		while (++count_h < 64)
		{
			count_w = -1;
			while (++count_w < 64 / 2)
			{
				if (count_w % 2)
					data2[count_h * 64 + count_w] = 0xFFFFFF;
				else
					data2[count_h * 64 + count_w] = 0xFF0000;
			}
		}
	*/	
}

void draw_minimap()
{
	render_square(&data->test_img, 0xBF40BF, DIR_SIZE, DIR_SIZE, 0 ,0);
	render_square(&data->player.img, 0xFF00, PLAYER_SIZE, PLAYER_SIZE, 0 , 0);
	render_square(&data->player.dir_img, 0xFF0000, DIR_SIZE, DIR_SIZE, 0 , 0);
	render_square(&data->mm_wall_img, 000000, WALL_SIZE, WALL_SIZE, 0 , 0);
	render_square(&data->mm_bg_img, 0xFFFFFF, BACKGROUND_SIZE, BACKGROUND_SIZE, 0, 0);
	
	manipulate_img();
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
	//int	biggest_line_size(char **map_array)
	//int	lines_amount(char **map_array)
	i = 0;
	while (i < 320)
	{
	//printf("RAY X: %f Y: %f\n", data->rays[i].x, data->rays[i].y);
	DDA(&data->mm_bg_img, data->player.x, data->player.y , data->rays[i].x, data->rays[i].y, 0xFF00);
	i++;
	}
	DDA(&data->mm_bg_img, data->player.x, data->player.y , data->player.dir_x , data->player.dir_y, 0xBF40BF);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 0);
	draw_player_mini_map();

	/* DRAW 3D WORLD */
	render_square(&data->game_img, 000000, WINDOW_WIDTH, WINDOW_HEIGHT, 0 , 0);
	
	render_square(&data->game_img, 0xffa500, WINDOW_WIDTH, WINDOW_HEIGHT/2, 0 , 0);
	
	i = 0;

	while (i < 320)
	{

		/*
	printf("OFFSET %f\n", data->rays[i].line_o);
	printf("distance to wall %f\n", data->rays[i].distance_to_wall);
	printf("sum: %f\n", data->rays[i].line_o + data->rays[i].distance_to_wall);
	*/
	DDA(&data->game_img, 0 + i, data->rays[i].line_o, 0 + i, data->rays[i].line_height + data->rays[i].line_o, 0xFF00);
	i++;
	}
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->game_img.mlx_img , 0, 300);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->texture_img.mlx_img , 0, 0);
	
}
