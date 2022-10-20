/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:41:17 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/20 02:24:59 by mamaro-d         ###   ########.fr       */
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

/*int	get_floor_color(char *rgb, t_data *data)
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
	data->floor_color = int_array;
	printf("%d\n", *data->floor_color);
	free_matrix((void **) rgb_array);
	return (1);
}*/



int get_ceiling_color(char *rgb, t_data *data)
{
	char	**rgb_array;
	char	*hex;
	char	*tmp;
	int		i;

	rgb_array = ft_split(rgb, ',');
	hex = ft_strdup("0x");
	i = -1;
	while(rgb_array[++i])
		if(!is_valid_rgb_value(rgb_array[i], rgb_array))
			return (0);
	
	i = -1;
	clear_rgb_array(&rgb_array);
	while(rgb_array[++i])
	{
		tmp = ft_strdup(hex);
		free(hex);
		hex = ft_strjoin(tmp, ft_rgb_to_hex(ft_atoi(rgb_array[i])));
		free(tmp);
	}
	free_matrix((void **)rgb_array);
	data->ceiling_color = hex;
	return (1);
}

int get_floor_color(char *rgb, t_data *data)
{
	char	**rgb_array;
	char	*hex;
	char	*tmp;
	int		i;

	rgb_array = ft_split(rgb, ',');
	hex = ft_strdup("0x");
	i = -1;
	while(rgb_array[++i])
		if(!is_valid_rgb_value(rgb_array[i], rgb_array))
			return (0);
	
	i = -1;
	clear_rgb_array(&rgb_array);
	while(rgb_array[++i])
	{
		tmp = ft_strdup(hex);
		free(hex);
		hex = ft_strjoin(tmp, ft_rgb_to_hex(ft_atoi(rgb_array[i])));
		free(tmp);
	}
	free_matrix((void **)rgb_array);
	data->floor_color = hex;
	return (1);
}

/*int	get_ceiling_color(char *rgb, t_data *data)
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
	data->ceiling_color = int_array;
	free_matrix(&rgb_array);
	return (1);
}*/

int	validate_rgb_colors(t_data *data, char **rgbs)
{
	if (!get_ceiling_color(rgbs[0], data) || !get_floor_color(rgbs[1], data))
		return (0);
	return (1);
}
