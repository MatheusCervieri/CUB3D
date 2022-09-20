/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_save_argument.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:19:49 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/09/20 19:20:20 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_save_argument(char *save_param)
{
	if(!ft_strncmp(save_param, "--save\0", 7))
		return (1);
	return (0);
}
