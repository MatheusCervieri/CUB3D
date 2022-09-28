/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:35:32 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/28 11:23:44 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(void)
{
	data->player.x = data->player.x + 1;
	data->player.dir_x = data->player.dir_x + 1;
	check_intersections();
	draw_minimap();
	printf("move\n");
}

void	move_left(void)
{
	data->player.x = data->player.x - 1;
	data->player.dir_x = data->player.dir_x - 1;
	check_intersections();
	draw_minimap();
	printf("move\n");
}

void	move_up(void)
{
	data->player.y = data->player.y - 1;
	data->player.dir_y = data->player.dir_y - 1;
	check_intersections();
	draw_minimap();
	printf("move\n");
}

void	move_down(void)
{
	data->player.y = data->player.y + 1;
	data->player.dir_y = data->player.dir_y + 1;
	check_intersections();
	draw_minimap();
	printf("move\n");
}
