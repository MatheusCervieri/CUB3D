#include "cub3d.h"

void    handle_error(char *error_message)
{
    ft_putstr_fd(error_message, 2);
    exit(1);
}

void    count_players(char c)
{
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W' )
        data->player_nbs++;
}

void    only_valid_caracters(char c)
{
    if (c != '\n' && !ft_strrchr("01NSEW", c))
			handle_error("Invalid char found in the map!");
}

void    valid_number_of_players()
{
    if(data->player_nbs != 1)
        handle_error("Invalid number of players!");
}

void    parse_map()
{
    //Checar se só tem um player.
    //Checar se todos os caracteres do mapa são válidos. 
    int i;
    i = 0;
    while (data->map_string[i])
    {
        count_players(data->map_string[i]);
        only_valid_caracters(data->map_string[i]);
        i++;
    }
    valid_number_of_players();
}