/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:13:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/05 18:39:17 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_empty_line(t_data *data, char *line)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' || line[i] != ' ')
			count++;
		i++;
	}
	if (count == 0)
		handle_error(data, "The map has a empty line\n");
}

void	check_sorrounded(t_data *data,
	char *line, char *up_line, char *down_line)
{
	size_t	i;
	
	i = data->tmp_i;
	if (i != 0)
		if (line[i - 1] != ' ' && line[i - 1] != '1')
			handle_error(data, "The map is not sorrounded by Walls\n");
	if ((i + 1) < ft_strlen(line))
		if (line[i + 1] != ' ' && line[i + 1] != '1')
			handle_error(data, "The map is not sorrounded by Walls\n");
	if (down_line)
		if (down_line[i] != ' ' && down_line[i] != '1')
			handle_error(data, "The map is not sorrounded by Walls\n");
	if (up_line)
		if (up_line[i] != ' ' && up_line[i] != '1')
			handle_error(data, "The map is not sorrounded by Walls\n");
}

void	check_valid_space_sorround_by_wall(t_data *data, char *line,
	char *up_line, char *down_line)
{
	size_t	i;
	data->tmp_i = 0;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			data->tmp_i = i; 
			check_sorrounded(data, line, up_line, down_line);
		}		
		i++;
	}
}
