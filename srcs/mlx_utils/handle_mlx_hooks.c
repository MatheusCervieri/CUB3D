/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:04:34 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/04 16:07:10 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_data *data)
{
	//free_mlx_imgs;
	free_mlx_core(data);
	exit(0);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_q)
		close_game(data);
	if (keycode == XK_d)
		move_right(data);
	if (keycode == XK_a)
		move_left(data);
	if (keycode == XK_w)
		move_up(data);
	if (keycode == XK_s)
		move_down(data);
	if (keycode == XK_Right)
		rotate_right(data);
	if (keycode == XK_Left)
		rotate_left(data);
	return (0);
}

void	handle_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, DestroyNotify,
		NoEventMask, &close_game, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &keypress, data);
	mlx_loop_hook(data->mlx, &render_loop, data);
}
