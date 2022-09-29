/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:41:17 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/09/29 10:57:46 by mamaro-d         ###   ########.fr       */
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
    int     *int_rgb_array;
	char	*tmp;

	rgb_array = ft_split(rgb, ',');
	int_rgb_array = (int *)malloc(sizeof(int) * 3);
    index = 0;
    while(rgb_array[index])
    {
		tmp = ft_strdup(rgb_array[index]);
		free(rgb_array[index]);
        rgb_array[index] = ft_strtrim(tmp, "F \n");
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

int	get_ceiling_color(char *rgb, t_data *data)
{
	char	**rgb_array;
	int		index;
    int     *int_rgb_array;
	char	*tmp;

	rgb_array = ft_split(rgb, ',');
    index = 0;
	int_rgb_array = (int *)malloc(sizeof(int) * 3);
    while(rgb_array[index])
    {
		tmp = ft_strdup(rgb_array[index]);
		free(rgb_array[index]);
        rgb_array[index] = ft_strtrim(tmp, "C \n");
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
    data->ceiling_color = int_rgb_array;
	return (1);
}

int validate_rgb_colors(t_data *data, char **rgbs)
{
	if(!get_ceiling_color(rgbs[0], data) || !get_floor_color(rgbs[1], data))
		return (0);
	return (1);
}
