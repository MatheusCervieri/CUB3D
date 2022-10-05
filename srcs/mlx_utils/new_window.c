/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:39:23 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/05 16:05:15 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data, t_img *img, char *dir)
{
	int	height;
	int	width;

	img->mlx_img = mlx_xpm_file_to_image(data->mlx, dir, &width, &height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
}

void	texture_initialization(t_data *data)
{
	init_textures(data, &data->txt_img[0], data->no_path);
	init_textures(data, &data->txt_img[1], data->so_path);
	init_textures(data, &data->txt_img[2], data->we_path);
	init_textures(data, &data->txt_img[3], data->ea_path);
}

void	new_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		handle_error(data, "MLX Error - Can't initialise mlx\n");
	data->win_ptr = mlx_new_window(data->mlx, 320, 200, "CUB3D");
	texture_initialization(data);
}
