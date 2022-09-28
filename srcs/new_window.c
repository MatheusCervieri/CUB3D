/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:39:23 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/28 11:14:59 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}