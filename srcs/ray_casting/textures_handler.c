/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:10:22 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/11 17:50:46 by mvieira-         ###   ########.fr       */
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
			data->texture1[i][j] = img_pix_get(&data->txt_img1, j , i);
			data->texture2[i][j] = img_pix_get(&data->txt_img2, j , i);
			data->texture3[i][j] = img_pix_get(&data->txt_img3, j , i);
			data->texture4[i][j] = img_pix_get(&data->txt_img4, j , i);
			j++;
		}
		i++;
	}
	
}

int get_texture_pixel(t_data *data, int x, int y, int pos)
{
	if (pos == 0)	
		return (data->texture1[y][x]);
	else if (pos == 1)
		return (data->texture2[y][x]);
	else if (pos == 2)
		return (data->texture3[y][x]);
	else if (pos == 3)
		return (data->texture4[y][x]);
	return (data->texture1[y][x]);
}