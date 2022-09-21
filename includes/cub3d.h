/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:24:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/21 17:35:25 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h> 
# include  <X11/X.h> 

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	char		*map_string;
    char        **map_array;
    int         player_nbs;
	void		*mlx;
	void		*win_ptr;
	t_img		img;
	t_img		img2; 
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

void using_img(void);

#endif