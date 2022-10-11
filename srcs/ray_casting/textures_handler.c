/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:10:22 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/11 17:34:34 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void save_texture_pixels(t_data *data)
{
	int i;
	int j;
	i = 0;
	while (i < 64)
	{
		j = 0;
		while(j < 64)
		{
			data->texture1[i][j] = img_pix_get(&data->txt_img3, j , i);
			j++;
		}
		i++;
	}
	
}

int get_texture_pixel(t_data *data, int x, int y)
{
	return (data->texture1[y][x]);
}