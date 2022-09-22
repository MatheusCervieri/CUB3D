/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:06:55 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/22 18:27:28 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rotate_right(void)
{
	rotate_player_dir(0.1, &data->player.dir_x, &data->player.dir_y, &data->player.rotation);
	draw_minimap();
}

void rotate_left(void)
{
	rotate_player_dir(-0.1, &data->player.dir_x, &data->player.dir_y, &data->player.rotation);
	draw_minimap();
}