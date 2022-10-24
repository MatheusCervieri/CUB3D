/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:47:18 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/24 20:01:40 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int player_on_wall(t_data *data, float x, float y)
{
	int i = 0;
	
	while (i < data->walls_nbs)
	{
		if (data->walls_position[i][0] == floor(x / MINI_MAP_SIZE)
			&& data->walls_position[i][1] == floor(y / MINI_MAP_SIZE))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	render_loop(t_data *data)
{
	check_intersections(data);
	if(player_on_wall(data, data->player.x, data->player.y) != 1)
		draw_3d_world(data);
	return (0);
}
