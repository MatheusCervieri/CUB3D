/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:56:23 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/18 14:54:30 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_util(int index, char ***rgb_array, int **int_array)
{
	while (--index >= 0)
	{
		if (is_valid_rgb_value(rgb_array[0][index], rgb_array[0]) != -1)
			int_array[0][index] = is_valid_rgb_value(rgb_array[0][index],
					rgb_array[0]);
		else
			return (0);
	}
	return (1);
}

int	get_no_texture(char *no_path, t_data *data)
{
	char	*parsed_path;
	int		fd;

	parsed_path = ft_strtrim(no_path, "NO \n");
	fd = open(parsed_path, O_RDONLY);
	if (fd != -1)
	{
		data->no_path = parsed_path;
		close(fd);
		return (1);
	}
	if (parsed_path != NULL)
		free(parsed_path);
	return (0);
}

int	get_so_texture(char *so_path, t_data *data)
{
	char	*parsed_path;
	int		fd;

	parsed_path = ft_strtrim(so_path, "SO \n");
	fd = open(parsed_path, O_RDONLY);
	if (fd != -1)
	{
		data->so_path = parsed_path;
		close(fd);
		return (1);
	}
	if (parsed_path != NULL)
		free(parsed_path);
	return (0);
}

int	get_ea_texture(char *ea_path, t_data *data)
{
	char	*parsed_path;
	int		fd;

	parsed_path = ft_strtrim(ea_path, "EA \n");
	fd = open(parsed_path, O_RDONLY);
	if (fd != -1)
	{
		data->ea_path = parsed_path;
		close(fd);
		return (1);
	}
	if (parsed_path != NULL)
		free(parsed_path);
	return (0);
}

int	get_we_texture(char *we_path, t_data *data)
{
	char	*parsed_path;
	int		fd;

	parsed_path = ft_strtrim(we_path, "WE \n");
	fd = open(parsed_path, O_RDONLY);
	if (fd != -1)
	{
		data->we_path = parsed_path;
		close(fd);
		return (1);
	}
	if (parsed_path != NULL)
		free(parsed_path);
	return (0);
}
