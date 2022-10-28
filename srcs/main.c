/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 04:24:46 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/28 15:34:52 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialization_functions(t_data *data)
{
	save_walls_position(data);
	get_player_first_position(data);
	check_intersections(data);
	new_window(data);
	init_imgs(data);
	handle_hooks(data);
	mlx_loop(data->mlx);
}

void	invalid_file(t_data *data)
{
	if (data->no_path == NULL)
		handle_error(data, "Invalid Texture \n");
	if (data->so_path == NULL)
		handle_error(data, "Invalid Texture \n");
	if (data->we_path == NULL)
		handle_error(data, "Invalid Texture \n");
	if (data->ea_path == NULL)
		handle_error(data, "Invalid Texture \n");
}

void	initialization(t_data *data)
{
	int	i;

	invalid_file(data);
	data->walls_position = NULL;
	data->walls_position = malloc(sizeof(double *) * data->walls_nbs);
	i = 0;
	while (i < data->walls_nbs)
	{
		data->walls_position[i] = malloc(sizeof(double) * 2);
		i++;
	}
	i = 0;
	while (i < 326)
	{
		data->rays[i].x = 0;
		data->rays[i].y = 0;
		data->rays[i].rotation = 0.0;
		data->rays[i].p = 0;
		i++;
	}
	initialization_functions(data);
}

void	init_vars(t_data *data)
{
	data->walls_position = NULL;
	data->map_string = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->map_array = NULL;
	data->texture_ok = 1;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		map;

	data = (t_data *)malloc(sizeof(t_data));
	init_vars(data);
	if (!validate_arguments(argc, argv))
	{
		free(data);
		return (1);
	}
	map = open(argv[1], O_RDONLY);
	if (map == -1)
	{
		free(data);
		return (msg_error("Map not found!\n"));
	}
	data->walls_nbs = 0;
	data->map_string = validate_map_params(map, data);
	data->player_nbs = 0;
	get_map_string(data, map);
	close(map);
	if (data->texture_ok == 0)
		handle_error(data, "Invalid Texture \n");
	if (data->texture_ok == -5)
		handle_error(data, "Invalid RGB \n");
	parse_map(data);
	initialization(data);
}
