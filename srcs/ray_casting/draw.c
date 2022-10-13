/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:31 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 21:27:10 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	distance_btw_two_points(float x1, float y1, float x2, float y2)
{
	float	distance;

	distance = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
	return (sqrt(distance));
}

void	init_img(t_data *data, t_img *img, int height, int width)
{
	img->mlx_img = mlx_new_image(data->mlx, height, width);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
}

void	init_imgs(t_data *data)
{
	init_img(data, &data->game_img, WINDOW_WIDTH, WINDOW_HEIGHT);
	init_img(data, &data->mm_bg_img, BACKGROUND_SIZE, BACKGROUND_SIZE);
}

void	draw_floor_ceiling(t_data *data)
{
	render_square(&data->game_img, *data->ceiling_color, WINDOW_WIDTH,
		WINDOW_HEIGHT);
	render_square(&data->game_img, *data->floor_color, WINDOW_WIDTH,
		WINDOW_HEIGHT / 2);
}

void	draw_3d_world(t_data *data)
{
	int		i;
	int		j;
	float	y_texture;
	float	y_texture_step;

	draw_floor_ceiling(data);
	i = 0;
	while (i < 320)
	{
		y_texture = 0;
		y_texture_step = 64 / (float) data->rays[i].line_height;
		j = 0;
		while (j < data->rays[i].line_height)
		{
			data->rays[i].pixel = get_texture_pixel(data,
					data->rays[i].x_texture, (int) y_texture, data->rays[i].p);
			img_pix_put(&data->game_img, 0 + i, j + data->rays[i].line_o,
				data->rays[i].pixel);
			y_texture += y_texture_step;
			j++;
		}
	i++;
	}
	mlx_put_image_to_window(data->mlx, data->win_ptr,
		data->game_img.mlx_img, 0, 0);
}
