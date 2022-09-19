/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheuscervieri <matheuscervieri@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:23:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/19 16:50:54 by matheuscerv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	int		fd;
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
	parse_map();
}
