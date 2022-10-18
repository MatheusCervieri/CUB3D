/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:47:33 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/18 14:52:30 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_p(t_data *data, char c, int width, int height)
{
	if (c == 'N')
	{
		data->player.x = width * MINI_MAP_SIZE;
		data->player.y = height * MINI_MAP_SIZE;
		data->player.rotation = 3 * PI / 2;
	}
	if (c == 'S')
	{
		data->player.x = width * MINI_MAP_SIZE;
		data->player.y = height * MINI_MAP_SIZE;
		data->player.rotation = PI / 2;
	}
	if (c == 'E')
	{
		data->player.x = width * MINI_MAP_SIZE;
		data->player.y = height * MINI_MAP_SIZE;
		data->player.rotation = 0;
	}
	if (c == 'W')
	{
		data->player.x = width * MINI_MAP_SIZE;
		data->player.y = height * MINI_MAP_SIZE;
		data->player.rotation = 2 * PI;
	}	
}

void	get_player_first_position(t_data *data)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = 0;
	width = 0;
	i = 0;
	while (data->map_array[i])
	{
		j = 0;
		while (data->map_array[i][j])
		{
			set_player_p(data, data->map_array[i][j], width, height);
			width++;
			j++;
		}
		width = 0;
		height++;
		i++;
	}
}

int	check_type(char *string, t_data *data)
{
	if (!ft_strncmp(string, "NO ", 3))
		return (get_no_texture(string, data));
	if (!ft_strncmp(string, "SO ", 3))
		return (get_so_texture(string, data));
	if (!ft_strncmp(string, "EA ", 3))
		return (get_ea_texture(string, data));
	if (!ft_strncmp(string, "WE ", 3))
		return (get_we_texture(string, data));
	if (!ft_strncmp(string, "F ", 2))
		return (get_floor_color(string, data));
	if (!ft_strncmp(string, "C ", 2))
		return (get_ceiling_color(string, data));
	return (2);
}

char	*validate_map_params(int map, t_data *data)
{
	int		status;
	char	*current_line;

	status = 1;
	while (status != 2)
	{
		current_line = get_next_line(map);
		status = check_type(current_line, data);
		if (!ft_strncmp(current_line, "\n\0", 2))
			status = 1;
		if (status == 2)
			break ;
		free(current_line);
		if (status == 0)
		{
			data->texture_ok = 0;
			return (ft_strdup("INVALID_TEXTURE"));
		}
	}
	return (current_line);
}

void	get_map_string(t_data *data, int map)
{
	char	*map_line;
	char	*tmp;
	
	map_line = ft_strdup("");
	while (map_line)
	{
		free(map_line);
		map_line = get_next_line(map);
		if (map_line)
		{
			tmp = ft_strdup(data->map_string);
			free(data->map_string);
			data->map_string = ft_strjoin(tmp,
					map_line);
			free(tmp);
		}
	}
}
