/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:35:32 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/25 04:42:31 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *data)
{
	data->player.y = data->player.y + sin(data->player.rotation + PI / 2) * 5;
	data->player.x = data->player.x + cos(data->player.rotation + PI / 2) * 5;
}

void	move_left(t_data *data)
{
	data->player.y = data->player.y + sin(data->player.rotation - PI / 2) * 5;
	data->player.x = data->player.x + cos(data->player.rotation - PI / 2) * 5;
}

int	is_wall(t_data *data, float x, float y)
{
	int	i;
	int	mx;
	int	my;

	mx = (int)(x) >> 6;
	my = (int)(y) >> 6;
	i = 0;
	while (i < data->walls_nbs)
	{
		if (data->walls_position[i][0] == mx &&
				data->walls_position[i][1] == my)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	move_up(t_data *data)
{
	int xo=0; if (data->player.rotation > PI / 2 && data->player.rotation < 3 * PI / 2){ xo=-110;} else{ xo=110;}                                    
 	int yo=0; if (data->player.rotation > PI){ yo=-110;} else{ yo=110;}                                   
 	int ipx=data->player.x, ipx_add_xo=(data->player.x+xo);          
 	int ipy=data->player.y, ipy_add_yo=(data->player.y+yo);
	if(is_wall(data, ipx, ipy_add_yo) == 0)
	{
	data->player.y = data->player.y + sin(data->player.rotation) * 5;
	}
	if(is_wall(data, ipx_add_xo, ipy) == 0)
	{
	data->player.x = data->player.x + cos(data->player.rotation) * 5;
	}
	/*
	if(is_wall(data, ipx, ipy) == 0)
	{
	data->player.y = data->player.y + sin(data->player.rotation) * 5;
	data->player.x = data->player.x + cos(data->player.rotation) * 5;
	}
	*/	
}

void	move_down(t_data *data)
{
	int xo=0; if (data->player.rotation > PI / 2 && data->player.rotation < 3 * PI / 2){ xo=-110;} else{ xo=110;}                                    
 	int yo=0; if (data->player.rotation > PI){ yo=-100;} else{ yo=100;}                                   
 	int ipx=data->player.x,ipx_sub_xo=(data->player.x-xo);             
 	int ipy=data->player.y,ipy_sub_yo=(data->player.y-yo);   
	
	if(is_wall(data, ipx, ipy_sub_yo) == 0)
	{
	data->player.y = data->player.y - sin(data->player.rotation) * 5;
	}
	if(is_wall(data, ipx_sub_xo, ipy) == 0)
	{
	data->player.x = data->player.x - cos(data->player.rotation) * 5;
	}
	
	
	
}
