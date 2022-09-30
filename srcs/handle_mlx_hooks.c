/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:04:34 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/30 16:04:43 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game()
{
	free_mlx_core();
	exit(0);
}

int	keypress(int keycode)
{
	if (keycode == XK_Escape || keycode == XK_q)
		close_game();
	if (keycode == XK_d)
		move_right();
	if (keycode == XK_a)
		move_left();
	if (keycode == XK_w)
		move_up();
	if (keycode == XK_s)
		move_down();
	if (keycode == XK_Right)
		rotate_right();
	if (keycode == XK_Left)
		rotate_left();


	return (0);
}

void	handle_hooks(void)
{
	mlx_hook(data->win_ptr, DestroyNotify,
		NoEventMask, &close_game, NULL);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &keypress, NULL);
	mlx_loop_hook(data->mlx, &render_loop, NULL);
}
