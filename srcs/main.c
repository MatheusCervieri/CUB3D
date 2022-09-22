/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:23:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/22 22:51:28 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data *data;

void get_player_first_position()
{
	int i;
	int j;
	int height;
	int width;

	height = 0; 
	width = 0;
	i = 0;
	while (data->map_array[i])
	{
		j = 0;
		while (data->map_array[i][j])
		{
			if(data->map_array[i][j] == 'N') //Add all. 
			{
				data->player.x = width * MINI_MAP_SIZE;
				data->player.y = height * MINI_MAP_SIZE;
			}
			width++;
			j++;
		}
		width = 0;
		height++;
		i++;
	}
}



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
	data->mlx = NULL;
	data->win_ptr = NULL;
	data->walls_nbs = 0;
	parse_map();

	//Inicializa o array. 
	data->walls_position = malloc(sizeof(double *) * data->walls_nbs);
	int i;
	i = 0;
	while (i < data->walls_nbs)
	{
		data->walls_position[i] = malloc(sizeof(double) * 2);
		i++;
	}
	save_walls_position();
	printf("%f", data->walls_position[0][0]);
	get_player_first_position();
	data->player.dir_y = data->player.y - 54; 
	data->player.dir_x = data->player.x + 13; 
	data->player.rotation = 0;
	new_window();
	
	draw_minimap();
	//mlx_destroy_image(data->mlx, data->img.mlx_img);
	handle_hooks();
	mlx_loop(data->mlx);
}

