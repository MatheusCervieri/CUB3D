/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:24:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/04 14:29:31 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>


typedef struct s_data
{
	char		*map_string;
    char		**map_array;
    int		 	player_nbs;
    char		*no_path;
    char		*so_path;
    char		*we_path;
    char		*ea_path;
    int 		*floor_color;
    int 		*ceiling_color;
}				t_data;

void    parse_map();

//Arguments parsing
int	validate_map_extension(char *map_name);
int	validate_save_argument(char *save_param);
int validate_arguments(int argc, char **argv);

//Get textures path
int get_no_texture(char *no_path, t_data *data);
int get_so_texture(char *so_path, t_data *data);
int get_ea_texture(char *ea_path, t_data *data);
int get_we_texture(char *we_path, t_data *data);

//set and validate rgb colors
int	get_floor_color(char *rgb, t_data *data);
int	get_ceiling_color(char *rgb, t_data *data);
int validate_rgb_colors(t_data *data, char **rgbs);

//print a new error msg on stderr and returns 1
int	msg_error(char *error);



#endif