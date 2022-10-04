/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:15:15 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/04 16:00:43 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_error(t_data *data, char *error_message)
{
	ft_putstr_fd(error_message, 2);
	free(data->map_string); //cuidar unsuded
	exit(1);
}

/*
mlx_destroy_img -->
init_textures(data, &data->texture_img[0], data->no_path);
init_textures(data, &data->texture_img[1], data->so_path);
init_textures(data, &data->texture_img[2], data->we_path);
init_textures(data, &data->texture_img[3], data->ea_path);
*/

void free_mlx_core(t_data *data)
{
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx, data->win_ptr);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}