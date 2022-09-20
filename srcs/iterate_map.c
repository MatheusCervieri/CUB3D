/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:10:18 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/20 12:34:00 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	last_map_lines(void)
{
	size_t	i;

	i = 0;
	while (data->map_array[i])
	{
		i++;
	}
	return (i);
}

void	char_is_one_or_space(char c)
{
	if (c != ' ' && c != '1')
		handle_error("The map is not sorrounded by Walls\n");
}

void	check_first_and_last_collum_element(char *line)
{
	char_is_one_or_space(line[0]);
	char_is_one_or_space(line[ft_strlen(line) - 1]);
}

void	check_valid_first_and_last_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' && !ft_strrchr("1  ", line[i]))
			handle_error("The map is not sorrounded by Walls\n");
		i++;
	}
}

void	iterate_map_array(void)
{
	size_t	i;

	i = 0;
	while (data->map_array[i])
	{
		if (i == 0)
			check_valid_first_and_last_line(data->map_array[i]);
		if (i == last_map_lines())
			check_valid_first_and_last_line(data->map_array[i]);
		check_first_and_last_collum_element(data->map_array[i]);
		if (i == 0)
		{		
			check_valid_space_sorround_by_wall(data->map_array[i],
				NULL, data->map_array[i + 1]);
		}
		else if (i == last_map_lines() - 1)
			check_valid_space_sorround_by_wall(data->map_array[i],
				data->map_array[i - 1], NULL);
		else
			check_valid_space_sorround_by_wall(data->map_array[i],
				data->map_array[i - 1], data->map_array[i + 1]);
		i++;
	}
}
