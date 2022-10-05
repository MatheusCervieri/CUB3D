/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:31 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/05 12:28:38 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void init_img(t_data *data, t_img *img, int height, int width)
{
	img->mlx_img = mlx_new_image(data->mlx, height, width);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
}

void init_imgs(t_data *data)
{
	init_img(data, &data->game_img, WINDOW_WIDTH , WINDOW_HEIGHT);
	init_img(data, &data->mm_bg_img, BACKGROUND_SIZE , BACKGROUND_SIZE);
	//render_square(&data->mm_bg_img, 0xFFFFFF, BACKGROUND_SIZE, BACKGROUND_SIZE, 0, 0);
	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 0);
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
	draw_3d_world(data);
}

