/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:15:15 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/20 20:58:46 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(1);
}

void free_mlx_core()
{
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx, data->win_ptr);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}