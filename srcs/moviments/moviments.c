/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:35:32 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/25 11:21:28 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	move_right(t_data *data)
{
	int		xo;
	int		yo;
	float	aux;

	xo = 0;
	yo = 0;
	if (data->player.rotation > PI / 2 && data->player.rotation < 3 * PI / 2)
		xo = xo + 110;
	else
		xo = xo - 110;
	if (data->player.rotation > PI)
		yo = yo + 110;
	else
		yo = yo - 110;
	aux = sin(data->player.rotation + PI / 2) * 5;
	if (is_wall(data, data->player.x, data->player.y + yo) == 0)
		data->player.y = data->player.y + aux;
	aux = cos(data->player.rotation + PI / 2) * 5;
	if (is_wall(data, data->player.x + xo, data->player.y) == 0)
		data->player.x = data->player.x + aux;
}

void	move_left(t_data *data)
{
	int		xo;
	int		yo;
	float	aux;

	xo = 0;
	yo = 0;
	if (data->player.rotation > PI / 2 && data->player.rotation < 3 * PI / 2)
		xo = xo - 110;
	else
		xo = xo + 110;
	if (data->player.rotation > PI)
		yo = yo - 110;
	else
		yo = yo + 110;
	aux = sin(data->player.rotation - PI / 2) * 5;
	if (is_wall(data, data->player.x, data->player.y + yo) == 0)
		data->player.y = data->player.y + aux;
	aux = cos(data->player.rotation - PI / 2) * 5;
	if (is_wall(data, data->player.x + xo, data->player.y) == 0)
		data->player.x = data->player.x + aux;
}

void	move_up(t_data *data)
{
	int	xo;
	int	yo;

	xo = 0;
	yo = 0;
	if (data->player.rotation > PI / 2 && data->player.rotation < 3 * PI / 2)
		xo = xo - 110;
	else
		xo = xo + 110;
	if (data->player.rotation > PI)
		yo = yo - 110;
	else
		yo = yo + 110;
	if (is_wall(data, data->player.x, data->player.y + yo) == 0)
		data->player.y = data->player.y + sin(data->player.rotation) * 5;
	if (is_wall(data, data->player.x + xo, data->player.y) == 0)
		data->player.x = data->player.x + cos(data->player.rotation) * 5;
}

void	move_down(t_data *data)
{
	int	xo;
	int	yo;

	xo = 0;
	yo = 0;
	if (data->player.rotation > PI / 2 && data->player.rotation < 3 * PI / 2)
		xo = xo + 110;
	else
		xo = xo - 110;
	if (data->player.rotation > PI)
		yo = yo + 110;
	else
		yo = yo - 110;
	if (is_wall(data, data->player.x, data->player.y + yo) == 0)
		data->player.y = data->player.y - sin(data->player.rotation) * 5;
	if (is_wall(data, data->player.x + xo, data->player.y) == 0)
		data->player.x = data->player.x - cos(data->player.rotation) * 5;
}
