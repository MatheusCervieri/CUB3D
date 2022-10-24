/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:56:23 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/24 23:36:44 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
