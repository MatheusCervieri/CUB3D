/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:15:15 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 00:54:16 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_error(t_data *data, char *error_message)
{
	ft_putstr_fd(error_message, 2);
	free(data->map_string);
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
