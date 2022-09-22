/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:24:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/22 18:26:11 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h> 
# include  <X11/X.h> 
# include <math.h>

# define PI 3.1415926535
# define MINI_MAP_SIZE 32

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	t_img	img;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	rotation;
	t_img	dir_img; 
}				t_player;

typedef struct s_data
{
	char		*map_string;
    char        **map_array;
    int         player_nbs;
	void		*mlx;
	void		*win_ptr;
	t_player	player;
	t_img		mm_wall_img;
	t_img		mm_bg_img;
}				t_data;

extern t_data	*data;

void    parse_map();
char **normalize_map(char **map_array);
void handle_error(char *error_message);
void iterate_map_array();
void check_valid_space_sorround_by_wall(char *line, char *up_line, char *down_line);
double rotate_player_dir(double speed, double *x, double *y, double *t);
void	new_window();
void	handle_hooks(void);
void free_mlx_core(void);
void	move_right(void);
void	move_left(void);
void	move_up(void);
void	move_down(void);
void	draw_minimap();
int render_loop(void);

void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
void	render_square(t_img *img, int color, int x, int y);
void 	rotate_right(void);
void 	rotate_left(void);

#endif