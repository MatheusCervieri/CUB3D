/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:31 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/21 21:25:34 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define PLAYER_SIZE 32
# define BACKGROUND_SIZE 300
# define WALL_SIZE 32
# define MINI_MAP_SIZE 32

void init_img(t_img *img, int height, int width)
{
	img->mlx_img = mlx_new_image(data->mlx, height, width);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
}

void draw_minimap()
{
	init_img(&data->player.img, PLAYER_SIZE , PLAYER_SIZE);
	init_img(&data->mm_wall_img, WALL_SIZE , WALL_SIZE);
	init_img(&data->mm_bg_img, BACKGROUND_SIZE , BACKGROUND_SIZE);
	render_square(&data->player.img, 0xFF00, PLAYER_SIZE, PLAYER_SIZE);
	render_square(&data->mm_wall_img, 000000, WALL_SIZE, WALL_SIZE);
	render_square(&data->mm_bg_img, 0xFFFFFF, BACKGROUND_SIZE, BACKGROUND_SIZE);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->mm_bg_img.mlx_img , 0, 0);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->player.img.mlx_img, 64, 64);
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
}
