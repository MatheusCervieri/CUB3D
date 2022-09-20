/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:19:41 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/09/20 19:20:40 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map_extension(char *map_name)
{
	int	len;
	int	index;

	len = ft_strlen(map_name);
	index = 0;
	while(index < len)
	{
		if(!ft_strncmp(&map_name[index], ".cub\0", 5))
			return (1);
		index++;
	}
	return (0);
}