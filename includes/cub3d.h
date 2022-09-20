/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:24:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/20 21:37:41 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h> 
# include  <X11/X.h> 

typedef struct s_data
{
	char		*map_string;
    char        **map_array;
    int         player_nbs;
	void		*mlx;
	void		*win_ptr;
}				t_data;

extern t_data	*data;

void    parse_map();
char **normalize_map(char **map_array);
void handle_error(char *error_message);
void iterate_map_array();
void check_valid_space_sorround_by_wall(char *line, char *up_line, char *down_line);
void	new_window();
void	handle_hooks(void);
void free_mlx_core(void);
void	move_right(void);
void	move_left(void);
void	move_up(void);
void	move_down(void);

#endif