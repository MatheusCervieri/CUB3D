/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:15:15 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 18:41:28 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void more_free(t_data *data)
{
	int i;

	if (data->no_path != NULL)
		free(data->no_path);
	if (data->so_path != NULL)
		free(data->so_path);
	if (data->we_path != NULL)
		free(data->we_path);
	if (data->ea_path != NULL)
		free(data->ea_path);
	if (data->floor_color != NULL)
		free(data->floor_color);
	if (data->ceiling_color != NULL)
		free(data->ceiling_color);
	i = 0;
	while (data->map_array[i])
	{
		free(data->map_array[i]);
		i++;
	}
	if (data->map_array != NULL)
		free(data->map_array);
}

void	handle_error(t_data *data, char *error_message)
{
	ft_putstr_fd(error_message, 2);
	free(data->map_string);
	more_free(data);
	exit(1);
}



void	free_mlx_core(t_data *data)
{
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx, data->win_ptr);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
