/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:19:29 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/18 14:19:00 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_arguments(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return (msg_error("Invalid number of arguments\n"));
	if (!validate_map_extension(argv[1]))
		return (msg_error("Not a valid map extension\n"));
	if (argc >= 3)
		return (msg_error("Invalid Number of Arguments \n"));
	return (1);
}
