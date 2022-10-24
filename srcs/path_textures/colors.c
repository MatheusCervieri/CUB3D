/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:41:17 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/19 02:26:07 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

int	is_valid_rgb_value(char *rgb, char **rgbs)
{
	int	value;

	value = ft_atoi(rgb);
	if (value > 255 || value < 0)
	{
		free_matrix((void **) rgbs);
		return (-1);
	}
	return (value);
}

int convert_to_hex(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[])
}

int	get_floor_color(char *rgb, t_data *data)
{
	char	**rgb_array;
	int		index;
	int		*int_array;
	char	*tmp;

	rgb_array = ft_split(rgb, ',');
	int_array = (int *)malloc(sizeof(int) * 3);
	index = 0;
	while (rgb_array[index])
	{
		tmp = ft_strdup(rgb_array[index]);
		free(rgb_array[index]);
		rgb_array[index] = ft_strtrim(tmp, "F \n");
		free(tmp);
		index++;
	}
	if (!(color_util(index, &rgb_array, &int_array)))
		return (0);
	data->floor_color = convert_to_hex(int_array);
	free_matrix((void **) rgb_array);
	free(int_array);
	return (1);
}

int	get_ceiling_color(char *rgb, t_data *data)
{
	char	**rgb_array;
	int		index;
	int		*int_array;
	char	*tmp;

	rgb_array = ft_split(rgb, ',');
	index = 0;
	int_array = (int *)malloc(sizeof(int) * 3);
	while (rgb_array[index])
	{
		tmp = ft_strdup(rgb_array[index]);
		free(rgb_array[index]);
		rgb_array[index] = ft_strtrim(tmp, "C \n");
		free(tmp);
		index++;
	}
	if (!(color_util(index, &rgb_array, &int_array)))
		return (0);
	data->ceiling_color = convert_to_hex(int_array);
	free_matrix((void **) rgb_array);
	free(int_array);
	return (1);
}

int	validate_rgb_colors(t_data *data, char **rgbs)
{
	if (!get_ceiling_color(rgbs[0], data) || !get_floor_color(rgbs[1], data))
		return (0);
	return (1);
}
