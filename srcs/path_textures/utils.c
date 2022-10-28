/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:00:28 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/24 23:54:44 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_to_hex(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	is_only_numbers(char **rgb)
{
	int	index;
	int	second_index;

	index = 0;
	second_index = 0;
	while (rgb[index])
	{
		while (rgb[index][second_index])
		{
			if (!ft_isdigit(rgb[index][second_index]))
				return (0);
			second_index++;
		}
		second_index = 0;
		index++;
	}
	return (1);
}
