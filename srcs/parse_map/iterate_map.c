/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:10:18 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 17:45:42 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	last_map_lines(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map_array[i])
	{
		i++;
	}
	return (i);
}

void	char_is_one_or_space(t_data *data, char c)
{
	if (c != ' ' && c != '1')
		handle_error(data, "The map is not sorrounded by Walls\n");
}

void	check_first_and_last_collum_element(t_data *data, char *line)
{
	char_is_one_or_space(data, line[0]);
	char_is_one_or_space(data, line[ft_strlen(line) - 1]);
}

void	check_valid_first_and_last_line(t_data *data, char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] != '\n' && !ft_strrchr("1  ", line[i]))
			handle_error(data, "The map is not sorrounded by Walls\n");
		i++;
	}
}

void	iterate_map_array(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map_array[i])
	{
		if (i == 0)
			check_valid_first_and_last_line(data, data->map_array[i]);
		if (i == last_map_lines(data))
			check_valid_first_and_last_line(data, data->map_array[i]);
		check_first_and_last_collum_element(data, data->map_array[i]);
		if (i == 0)
		{		
			check_valid_space_sorround_by_wall(data, data->map_array[i],
				NULL, data->map_array[i + 1]);
		}
		else if (i == last_map_lines(data) - 1)
			check_valid_space_sorround_by_wall(data, data->map_array[i],
				data->map_array[i - 1], NULL);
		else
			check_valid_space_sorround_by_wall(data, data->map_array[i],
				data->map_array[i - 1], data->map_array[i + 1]);
		i++;
	}
}
