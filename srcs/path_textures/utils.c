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

char	*ft_rgb_to_hex(int rgb)
{
	char	*base;
	char	hex[2];

	base = "0123456789abcdef";
	if (rgb == 0)
		return (ft_strdup("00"));
	hex[1] = base[rgb % 16];
	rgb /= 16;
	hex[0] = base[rgb % 16];
	return (ft_strdup(hex));
}

int	convert_to_hex(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	validate_rgb_colors(t_data *data, char **rgbs)
{
	if (!get_ceiling_color(rgbs[0], data) || !get_floor_color(rgbs[1], data))
		return (0);
	return (1);
}
