/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:56:41 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/13 17:18:27 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	biggest_line_size(char **map_array)
{
	int	i;
	int	tmp;
	int	aux;

	i = 0;
	while (map_array[i])
	{
		if (i == 0)
			aux = ft_strlen(map_array[i]);
		else
		{
			tmp = ft_strlen(map_array[i]);
			if (tmp > aux)
				aux = tmp;
		}	
		i++;
	}
	return (aux);
}

int	lines_amount(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		i++;
	}
	return (i);
}

char	*ft_calloc_space(size_t nelem, size_t elsize)
{
	char	*allocated_memory;
	int		over_handling;

	over_handling = nelem * elsize;
	if (nelem != 0 && over_handling / nelem != elsize)
		return (NULL);
	allocated_memory = (void *) malloc (nelem * elsize);
	if (allocated_memory == NULL)
		return (NULL);
	ft_memset(allocated_memory, ' ', nelem * elsize);
	allocated_memory[nelem * elsize - 1] = '\0'; 
	return (allocated_memory);
}

char	**normalize_map(char **map_array)
{
	char	**normalized_map;
	int		i;

	normalized_map = malloc(sizeof(char *) * lines_amount(map_array));
	i = 0;
	while (i < lines_amount(map_array))
	{
		normalized_map[i] = ft_calloc_space(biggest_line_size(map_array),
				sizeof(char));
		i++;
	}
	i = 0;
	while (i < lines_amount(map_array))
	{
		ft_memmove(normalized_map[i], map_array[i], ft_strlen(map_array[i]));
		i++;
	}
	return (normalized_map);
}
