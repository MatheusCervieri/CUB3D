/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:00:28 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/24 16:23:55 by mvieira-         ###   ########.fr       */
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
