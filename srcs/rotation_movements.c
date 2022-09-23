/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:06:55 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/23 21:26:33 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rotate_right(void)
{
	rotate_player_dir(0.1, &data->player.dir_x, &data->player.dir_y, &data->player.rotation);
	
	if(data->player.rotation > 2 * PI)
		data->player.rotation = 0;

	printf("%f\n", data->player.rotation);
	check_intersections();
	draw_minimap();
}

void rotate_left(void)
{
	rotate_player_dir(-0.1, &data->player.dir_x, &data->player.dir_y, &data->player.rotation);

	if(data->player.rotation < 0)
		data->player.rotation = 2 * PI;
	
	printf("%f\n", data->player.rotation);
	check_intersections();
	draw_minimap();
}