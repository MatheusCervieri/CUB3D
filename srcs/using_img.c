/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:24:24 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/21 17:44:10 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; 
	int		line_len;
	int		endian;
}	t_img;
*/

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 300)
	{
		j = 0;
		while (j < 300)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	render_img2(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 150)
	{
		j = 0;
		while (j < 150)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void using_img(void)
{
	data->img.mlx_img = mlx_new_image(data->mlx, 300, 300); 
	data->img2.mlx_img = mlx_new_image(data->mlx, 150, 150); 
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img2.addr = mlx_get_data_addr(data->img2.mlx_img, &data->img2.bpp,
			&data->img2.line_len, &data->img2.endian);
	render_background(&data->img, 0xFF00);
	render_img2(&data->img2, 0xFF0000);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->img.mlx_img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->img2.mlx_img, 30, 60);
}
