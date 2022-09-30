/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:35:32 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/30 16:39:57 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(void)
{
	data->player.y = data->player.y + sin(data->player.rotation + PI/2)*5;
	data->player.x = data->player.x + cos(data->player.rotation+ PI/2)*5;
	check_intersections();
	//draw_minimap();
	
}

void	move_left(void)
{
	data->player.y = data->player.y + sin(data->player.rotation - PI/2)*5;
	data->player.x = data->player.x + cos(data->player.rotation - PI/2)*5;
	check_intersections();
	//draw_minimap();
}

void	move_up(void)
{
	data->player.y = data->player.y + sin(data->player.rotation)*5;
	data->player.x = data->player.x + cos(data->player.rotation)*5;
	check_intersections();
	//draw_minimap();

}

void	move_down(void)
{
	data->player.y = data->player.y - sin(data->player.rotation)*5;
	data->player.x = data->player.x - cos(data->player.rotation)*5;
	data->player.y = data->player.y + 1;
	data->player.dir_y = data->player.dir_y + 1;
	check_intersections();
	//draw_minimap();
	
}
