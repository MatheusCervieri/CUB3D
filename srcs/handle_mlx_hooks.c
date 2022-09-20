/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:04:34 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/20 21:26:25 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game()
{
	exit(0);
}

int	keypress(int keycode)
{
	if (keycode == XK_Escape || keycode == XK_q)
		printf("ESC\n");
	/*
	if (keycode == XK_Right || keycode == XK_d)
		move_right(game);
	if (keycode == XK_Left || keycode == XK_a)
		move_left(game);
	if (keycode == XK_Up || keycode == XK_w)
		move_up(game);
	if (keycode == XK_Down || keycode == XK_s)
		move_down(game);
	*/
	return (0);
}

void	handle_hooks(void)
{
	mlx_hook(data->win_ptr, DestroyNotify,
		NoEventMask, &close_game, NULL);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &keypress, NULL);
	//mlx_loop_hook(game->mlx, &render_loop, game);
}
