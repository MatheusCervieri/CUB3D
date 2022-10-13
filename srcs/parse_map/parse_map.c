/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:19:05 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 17:07:11 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_there_empty_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_string[i])
	{
		if (data->map_string[i] == '\n' && data->map_string[i + 1] == '\n')
			handle_error(data, "There is a empty line in the map\n");
		i++;
	}
}

void free_matrix_char(char **matrix)
{
	int	i;

	i = 0;
	while(matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	valid_number_of_players(t_data *data)
{
	if (data->player_nbs != 1)
		handle_error(data, "Invalid number of players! \n");
}

void	count_players(t_data *data, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		data->player_nbs++;
}

void	only_valid_caracters(t_data *data, char c)
{
	if (c != '\n' && !ft_strrchr("01NSEW ", c))
		handle_error(data, "Invalid char found in the map!");
}

void	parse_map(t_data *data)
{
	size_t	i;
	char	**map_array;

	i = 0;
	while (data->map_string[i])
	{
		if (data->map_string[i] == '1')
			data->walls_nbs++;
		count_players(data, data->map_string[i]);
		only_valid_caracters(data, data->map_string[i]);
		i++;
	}
	is_there_empty_line(data);
	valid_number_of_players(data);
	map_array = ft_split(data->map_string, '\n');
	data->map_array = normalize_map(map_array);
	free_matrix_char(map_array);
	iterate_map_array(data);
}
