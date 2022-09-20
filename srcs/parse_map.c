/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:19:05 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/20 09:55:23 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t last_map_lines()
{
	size_t	i;
	i = 0;
	while (data->map_array[i])
	{
		i++;
	}
	return (i);
}

void handle_error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(1);
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

void valid_number_of_players()
{
	if (data->player_nbs != 1)
		handle_error("Invalid number of players! \n");
}

void check_valid_first_and_last_line(char *line)
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


void	is_empty_line(char *line)
{
	size_t	i;
	int count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' || line[i] != ' ')
			count++;
		i++;
	}
	if (count == 0)
			handle_error("The map has a empty line\n");
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

void check_sorrounded(size_t i, char *line, char *up_line, char *down_line)
{
	
	if(i != 0)
		if(line[i - 1] != ' ' && line[i - 1] != '1')
			handle_error("The map is not sorrounded by Walls\n");

	if (ft_strlen(line) > i)
		if(line[i + 1] != ' ' && line[i + 1] != '1')
			handle_error("The map is not sorrounded by Walls\n");

	if (down_line && ft_strlen(down_line) > i)
		if(down_line[i] != ' ' && down_line[i] != '1')
		{
			
			handle_error("The map is not sorrounded by Walls\n");
		}
	if (up_line && ft_strlen(up_line) > i)
	{
		if(up_line[i] != ' ' && up_line[i] != '1')
			handle_error("The map is not sorrounded by Walls\n");
	}
}

void check_valid_space_sorround_by_wall(char *line, char *up_line, char *down_line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if(line[i] == ' ')
			check_sorrounded(i, line, up_line, down_line);
		i++;
	}
}

void iterate_map_array()
{
	size_t i;
	i = 0; 
	while (data->map_array[i])
	{
		if (i == 0)
			check_valid_first_and_last_line(data->map_array[i]);
		if(i == last_map_lines(data->map_array))
			check_valid_first_and_last_line(data->map_array[i]);
		//falta checar a última linha. 
		//is_empty_line(data->map_array[i]);
		check_first_and_last_collum_element(data->map_array[i]);
		if(i == 0)
		{		
			check_valid_space_sorround_by_wall(data->map_array[i], NULL, data->map_array[i + 1]);
		}
		else if (i == last_map_lines(data->map_array) - 1)
			check_valid_space_sorround_by_wall(data->map_array[i], data->map_array[i - 1],	NULL);
		else
			check_valid_space_sorround_by_wall(data->map_array[i], data->map_array[i - 1],	data->map_array[i + 1]);
		i++;
	}
}

//Checar se nao ha uma linha vazia no meio do mapa

//Descobrir o tamanho da maior linha.
//Descobrir a quantidad de linhas.
//Alocar memória para cada uma das linhas e colocar espaço em cada um dos caracteres.
// Colocar os caracteres do mapa em cada uma das linhas.


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

void parse_map()
{
	size_t i;

	i = 0;
	while (data->map_string[i])
	{
		count_players(data->map_string[i]);
		only_valid_caracters(data->map_string[i]);
		i++;
	}
	is_there_empty_line();
	valid_number_of_players();
	data->map_array = ft_split(data->map_string, '\n');
	iterate_map_array();
}