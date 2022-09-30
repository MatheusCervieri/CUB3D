/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:39:23 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/30 15:01:01 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_textures(t_img *img, int height, int width, char *dir)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx, dir, &width, &height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	printf("Width %i", width);
}

void	texture_initialization()
{
	init_textures(&data->texture_img[0], 64 , 64, data->no_texture);
	init_textures(&data->texture_img[1], 64 , 64, data->so_texture);
	init_textures(&data->texture_img[2], 64 , 64, data->we_texture);
	init_textures(&data->texture_img[3], 64 , 64, data->ea_texture);
}

void	new_window()
{
	int	width;
	int	height;

	data->mlx = mlx_init();
	if (data->mlx == NULL)
		handle_error("MLX Error - Can't initialise mlx\n");
	width = 64;
	height = 64;
	data->win_ptr = mlx_new_window(data->mlx, 700, 700, "CUB3D");
	texture_initialization();
}