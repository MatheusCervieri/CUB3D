/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:41:17 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/24 22:47:25 by mvieira-         ###   ########.fr       */
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

void clear_rgb_array(char ***rgb_array)
{
	char	*tmp;
	int		index;

	index = -1;
	while ((*rgb_array)[++index])
	{
		tmp = ft_strdup((*rgb_array)[index]);
		free((*rgb_array)[index]);
		(*rgb_array)[index] = ft_strtrim(tmp, "CF \n");
		free(tmp);
	}
}

int	is_valid_rgb_value(char *rgb, char **rgbs)
{
	int	value;

	value = ft_atoi(rgb);
	if (value > 255 || value < 0)
	{
		free_matrix((void **)rgbs);
		return (0);
	}
	return (1);
}

int convert_to_hex(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	get_floor_color(char *rgb, t_data *data)
{
	char	**rgb_array;
	int		index;
	int		int_array[3];
	char	*tmp;

	rgb_array = ft_split(rgb, ',');
	index = 0;
	while (rgb_array[index])
	{
		tmp = ft_strdup(rgb_array[index]);
		free(rgb_array[index]);
		rgb_array[index] = ft_strtrim(tmp, "F \n");
		int_array[index] = ft_atoi(rgb_array[index]);
		free(tmp);
		index++;
	}
	/* if (!(color_util(index, &rgb_array, &int_array)))
		return (0); */
	data->floor_color = convert_to_hex(int_array);
	printf("%d\n", data->floor_color);
	printf("R %d\n", int_array[0]);
	printf("G %d\n", int_array[1]);
	printf("B %d\n", int_array[2]);
	free_matrix((void **) rgb_array);
	return (1);
}

int	get_ceiling_color(char *rgb, t_data *data)
{
	char	**rgb_array;
	int		index;
	int		int_array[3];
	char	*tmp;

	rgb_array = ft_split(rgb, ',');
	index = 0;
	while (rgb_array[index])
	{
		tmp = ft_strdup(rgb_array[index]);
		free(rgb_array[index]);
		rgb_array[index] = ft_strtrim(tmp, "F \n");
		int_array[index] = ft_atoi(rgb_array[index]);
		free(tmp);
		index++;
	}
	/* if (!(color_util(index, &rgb_array, &int_array)))
		return (0); */
	data->ceiling_color = convert_to_hex(int_array);
	printf("%d\n", data->floor_color);
	printf("R %d\n", int_array[0]);
	printf("G %d\n", int_array[1]);
	printf("B %d\n", int_array[2]);
	free_matrix((void **) rgb_array);
	return (1);
}

int	validate_rgb_colors(t_data *data, char **rgbs)
{
	if (!get_ceiling_color(rgbs[0], data) || !get_floor_color(rgbs[1], data))
		return (0);
	return (1);
}
