/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:19:29 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/10/07 10:13:31 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_arguments(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return (msg_error("Invalid number of arguments\n"));
	if (!validate_map_extension(argv[1]))
		return (msg_error("Not a valid map extension\n"));
	if (argc == 3 && !validate_save_argument(argv[2]))
		return (msg_error("The second argument must be \"--save\" \n"));
	return (1);
}
