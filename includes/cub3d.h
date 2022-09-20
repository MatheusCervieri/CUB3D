/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:24:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/20 19:31:56 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>


typedef struct s_data
{
	char		*map_string;
    char        **map_array;
    int         player_nbs;
}				t_data;

t_data *data;

void    parse_map();

//Arguments parsing

int	validate_map_extension(char *map_name);
int	validate_save_argument(char *save_param);
int validate_arguments(int argc, char **argv);

//print a new error msg on stderr and returns 1
int	msg_error(char *error);

#endif