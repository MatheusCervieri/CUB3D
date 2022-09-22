/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:41:17 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/09/21 21:22:18 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_rgb_value(char *rgb)
{
	int value;

	value = ft_atoi(rgb);
	if(value > 255 || value < 0)
        return (-1);
	return (value);
}

int	get_floor_color(char *rgb, t_data *data)
{
	char	**rgb_array;
	int		index;
    int     int_rgb_array[3];
	char	*tmp;

	rgb_array = ft_split(rgb, ',');
    index = 0;
    while(rgb_array[index])
    {
		tmp = ft_strdup(rgb_array[index]);
		free(rgb_array[index]);
        rgb_array[index] = ft_strtrim(tmp, " ");
		free(tmp);
        index++;
    }
    while(--index >= 0)
    {
		if(is_valid_rgb_value(rgb_array[index]) != -1)
        	int_rgb_array[index] = is_valid_rgb_value(rgb_array[index]);
		else
			return (0);
    }
    data->floor_color = int_rgb_array;
	return (1);
}