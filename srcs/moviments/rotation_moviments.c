/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_moviments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:06:55 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/05 16:06:45 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_data *data)
{
	data->player.rotation = data->player.rotation + 0.1;
	if (data->player.rotation > 2 * PI)
		data->player.rotation = data->player.rotation - (2 * PI);
}

void	rotate_left(t_data *data)
{
	data->player.rotation = data->player.rotation - 0.1;
	if (data->player.rotation < 0)
		data->player.rotation = data->player.rotation + (2 * PI);
}
