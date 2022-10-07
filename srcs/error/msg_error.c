/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:17:29 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/07 10:30:46 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	msg_error(char *error)
{
	int	len;

	len = ft_strlen(error);
	write(2, "Error: ", 7);
	write(2, error, len);
	return (0);
}
