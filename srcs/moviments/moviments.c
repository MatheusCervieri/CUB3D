/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:35:32 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/04 16:08:13 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *data)
{
	data->player.y = data->player.y + sin(data->player.rotation + PI/2)*5;
	data->player.x = data->player.x + cos(data->player.rotation+ PI/2)*5;
	//check_intersections();
	//draw_minimap();
	
}

void	move_left(t_data *data)
{
	data->player.y = data->player.y + sin(data->player.rotation - PI/2)*5;
	data->player.x = data->player.x + cos(data->player.rotation - PI/2)*5;
	//check_intersections();
	//draw_minimap();
}

void	move_up(t_data *data)
{
	data->player.y = data->player.y + sin(data->player.rotation)*5;
	data->player.x = data->player.x + cos(data->player.rotation)*5;
	//check_intersections();
	//draw_minimap();

}

void	move_down(t_data *data)
{
	data->player.y = data->player.y - sin(data->player.rotation)*5;
	data->player.x = data->player.x - cos(data->player.rotation)*5;
	data->player.y = data->player.y + 1;
	data->player.dir_y = data->player.dir_y + 1;
	//check_intersections();
	//draw_minimap();
}
