/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:23:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/21 22:52:11 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
	char *string = "1, 244, 0 | 250, 133, 93";
	char **rgbs = ft_split(string, '|');
	if(!validate_arguments(argc, argv))
		return (1);
	if(!validate_rgb_colors(data, rgbs))
		return(msg_error("Invalid RGB Color\n"));
	printf("all params are good\n");
    

    
/* 	int		fd;
	char	*map_line;
	data = malloc(sizeof(t_data));
	data->map_string = ft_strdup("");

	fd = open("teste.txt", O_RDONLY);
	map_line = get_next_line(fd);
	data->map_string = ft_strjoin(data->map_string, map_line);

	while (map_line)
	{
		map_line = get_next_line(fd);
		if(map_line)
			data->map_string = ft_strjoin(data->map_string,
					map_line);
	}

	
	data->player_nbs = 0; 
	parse_map(); */
}
