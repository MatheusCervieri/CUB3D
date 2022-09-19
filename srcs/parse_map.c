#include "cub3d.h"

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
		handle_error("Invalid number of players!");
}

void check_valid_first_and_last_line(char *line)
{
	int	i;
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
	int	i;
	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' || line[i] != ' ')
			handle_error("The map has a empty line\n");
		i++;
	}
}

void	char_is_one_or_space(char c)
{
	if (c != ' ' || c != '1')
		handle_error("The map is not sorrounded by Walls\n");
}

void	check_first_and_last_collum_element(char *line)
{
	char_is_one_or_space(line[0]);
	char_is_one_or_space(line[ft_strlen(line) - 1]);
}

void iterate_map_array()
{
	int i;
	i = 0; 
	while (data->map_array[i])
	{
		if (i == 0)
			check_valid_first_and_last_line(data->map_array[i]);
		//falta checar a última linha. 
		is_empty_line(data->map_array[i]);
		check_first_and_last_collum_element(data->map_array[i]);
		i++;
	}
}

// Checar se nao ha uma linha vazia no meio do mapa
// Checar se na 1a linha, ultima linha, so existem espaços ou 1
//1a coluna e ultima coluna so existem espaços ou 1
// Checar para cada espaço se os 8 caracteres ao redor são “1” ou “espaço” (essa lógica
// garante que o mapa eh fechado por paredes)

void parse_map()
{
	int i;

	i = 0;
	while (data->map_string[i])
	{
		count_players(data->map_string[i]);
		only_valid_caracters(data->map_string[i]);
		i++;
	}
	valid_number_of_players();
	data->map_array = ft_split(data->map_string, '\n');
	iterate_map_array();
}