/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:04:34 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 01:30:54 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_params(t_data *data)
{
	free(data->ceiling_color);
	free(data->floor_color);
	free(data->ea_path);
	free(data->we_path);
	free(data->no_path);
	free(data->so_path);
	while(*(data->map_array))
	{
		free(*(data->map_array));
		data->map_array++;
	}
	free(data->map_array);
	free(data->map_string);

}

int	close_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->game_img.mlx_img);
	mlx_destroy_image(data->mlx, data->mm_bg_img.mlx_img);
	mlx_destroy_image(data->mlx, data->txt_img1.mlx_img);
	mlx_destroy_image(data->mlx, data->txt_img2.mlx_img);
	mlx_destroy_image(data->mlx, data->txt_img3.mlx_img);
	mlx_destroy_image(data->mlx, data->txt_img4.mlx_img);
	free_mlx_core(data);
	free_params(data);
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
