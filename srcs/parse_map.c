/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:19:05 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/20 12:10:23 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void is_there_empty_line()
{
	int	i;
	i = 0;
	while (data->map_string[i])
	{
		if(data->map_string[i] == '\n' && data->map_string[i + 1] == '\n')
			handle_error("There is a empty line in the map\n");
		i++;
	}
}

void valid_number_of_players()
{
	if (data->player_nbs != 1)
		handle_error("Invalid number of players! \n");
}

void count_players(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		data->player_nbs++;
}

void only_valid_caracters(char c)
{
	if (c != '\n' && !ft_strrchr("01NSEW ", c))
		handle_error("Invalid char found in the map!");
}

void parse_map()
{
	size_t i;
	char	**map_array;

	i = 0;
	while (data->map_string[i])
	{
		count_players(data->map_string[i]);
		only_valid_caracters(data->map_string[i]);
		i++;
	}
	is_there_empty_line();
	valid_number_of_players();
	map_array = ft_split(data->map_string, '\n');
	data->map_array = normalize_map(map_array);
	free(map_array);
	iterate_map_array();
}