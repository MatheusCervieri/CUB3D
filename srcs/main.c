/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:23:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/04 21:27:44 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_type(char *string, t_data *data)
{
	if(!ft_strncmp(string, "NO ", 3))
		return(get_no_texture(string, data));
	if(!ft_strncmp(string, "SO ", 3))
		return(get_so_texture(string, data));
	if(!ft_strncmp(string, "EA ", 3))
		return(get_ea_texture(string, data));
	if(!ft_strncmp(string, "WE ", 3))
		return(get_we_texture(string, data));
	if(!ft_strncmp(string, "F ", 2))
		return(get_floor_color(string, data));
	if(!ft_strncmp(string, "C ", 2))
		return(get_ceiling_color(string, data));
	return (2);
}

char	*validate_map_params(int map, t_data *data)
{
	int		status;
	char	*current_line;

	status = 1;
	while(status != 2)
	{
		current_line = get_next_line(map);
		status = check_type(current_line, data);
		if(!ft_strncmp(current_line, "\n\0", 2))
			status = 1;
		if(status == 2)
			break ;
		free(current_line);
		if(status == 0)
			return ("");
	}
	return (current_line);

}

void get_player_first_position(t_data *data)
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
				data->player.rotation = 3*PI/2;
			}
			if(data->map_array[i][j] == 'S') //Add all. 
			{
				data->player.x = width * MINI_MAP_SIZE;
				data->player.y = height * MINI_MAP_SIZE;
				data->player.rotation = PI/2;
			}
			if(data->map_array[i][j] == 'E') //Add all. 
			{
				data->player.x = width * MINI_MAP_SIZE;
				data->player.y = height * MINI_MAP_SIZE;
				data->player.rotation = 0;
			}
			if(data->map_array[i][j] == 'W') //Add all. 
			{
				data->player.x = width * MINI_MAP_SIZE;
				data->player.y = height * MINI_MAP_SIZE;
				data->player.rotation = 2*PI;
			}
			width++;
			j++;
		}
		width = 0;
		height++;
		i++;
	}
		
}


int	main(int argc, char **argv)
{
	t_data *data;
	int		map;
	char	*map_line;

    data = (t_data *)malloc(sizeof(t_data));
	if(!validate_arguments(argc, argv))
		return (1);
	map = open(argv[1], O_RDONLY);
	if(map == -1)
		return (msg_error("Map not found"));
	/*
		if(!validate_rgb_colors(data, rgbs))
		return(msg_error("Invalid RGB Color\n"));
	*/
	data->map_string = validate_map_params(map,data);
	map_line = data->map_string;
	while (map_line)
	{
		map_line = get_next_line(map);
		if(map_line)
			data->map_string = ft_strjoin(data->map_string,
					map_line);
	}
	close(map);
	parse_map(data);
	
	data->walls_position = malloc(sizeof(double *) * data->walls_nbs);
	int i;
	i = 0;
	while (i < data->walls_nbs)
	{
		data->walls_position[i] = malloc(sizeof(double) * 2);
		i++;
	}
	save_walls_position(data);
	get_player_first_position(data);

	i = 0;
	while (i < 320)
	{
	data->rays[i].x = 0;
	data->rays[i].y = 0;
	data->rays[i].rotation = 0.0;
	data->rays[i].position = 0;
	i++;
	}
	check_intersections(data);
	new_window(data);
	init_imgs(data);
	draw_minimap(data);
	handle_hooks(data);
	mlx_loop(data->mlx);
}
