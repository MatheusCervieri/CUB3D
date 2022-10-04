/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_moviments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:06:55 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/04 21:26:29 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rotate_right(t_data *data)
{
	//rotate_player_dir(0.1, &data->player.dir_x, &data->player.dir_y, &data->player.rotation);
	data->player.rotation = data->player.rotation + 0.1;
	if(data->player.rotation > 2 * PI)
		data->player.rotation = data->player.rotation - (2 * PI);
	check_intersections(data);
	//draw_minimap();
}

void rotate_left(t_data *data)
{
	//rotate_player_dir(-0.1, &data->player.dir_x, &data->player.dir_y, &data->player.rotation);
	data->player.rotation = data->player.rotation - 0.1;
	if(data->player.rotation < 0)
		data->player.rotation = data->player.rotation + (2 * PI);
	check_intersections(data);
	//draw_minimap();
}