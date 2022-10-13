/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:04:34 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 19:50:54 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->game_img.mlx_img);
	mlx_destroy_image(data->mlx, data->mm_bg_img.mlx_img);
	mlx_destroy_image(data->mlx, data->txt_img1.mlx_img);
	mlx_destroy_image(data->mlx, data->txt_img2.mlx_img);
	mlx_destroy_image(data->mlx, data->txt_img3.mlx_img);
	mlx_destroy_image(data->mlx, data->txt_img4.mlx_img);
	free_mlx_core(data);
	more_free(data);
	if (data->map_string != NULL)
		free(data->map_string);
	free(data);
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
