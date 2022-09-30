/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:24:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/30 16:16:10 by mvieira-         ###   ########.fr       */
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
# define DG 0.0174533
# define MINI_MAP_SIZE 16
# define WINDOW_WIDTH 320
# define WINDOW_HEIGHT 200

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ray
{
	t_img	img;
	double	x;
	double	y;
	double	h_x;
	double	h_y;
	double	v_x;
	double 	v_y;
	int		pixel;
	double	x_texture;
	double distance_to_wall;
	double line_height;
	double line_o;
	double	rotation;
	double diference_angle;
	int		position;
}				t_ray;

typedef struct s_player
{
	t_img	img;
	double	x;
	double	y;
	double 	dx;
	double	dy;
	double	dir_x;
	double	dir_y;
	double 	test_x;
	double	test_y;
	double	rotation;
	t_img	dir_img; 
}				t_player;

typedef struct s_data
{
	char		*map_string;
    char        **map_array;
    int         player_nbs;
	int			player_dir;
	int			walls_nbs;
	double		**walls_position;
	void		*mlx;
	void		*win_ptr;
	int 		*floor_color;
    int 		*ceiling_color;
	char		*no_texture;
    char		*so_texture;
    char		*we_texture;
    char		*ea_texture;
	t_ray		rays[320];
	t_img		texture_img[4];
	t_img		game_img;
	t_img		line_img;
	t_player	player;
	t_img		mm_wall_img;
	t_img		mm_bg_img;
	t_img		test_img;
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
int	lines_amount(char **map_array);
int	biggest_line_size(char **map_array);
void init_imgs(void);
void	render_square(t_img *img, int color, int x, int y, int real_x, int real_y);

double distance_btw_two_points(float x1, float y1, float x2, float y2);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
void 	rotate_right(void);
void 	rotate_left(void);
void	save_walls_position(void);
int	check_horizontal_intersections(double *new_x, double *new_y, double rotation);
int	check_vertical_intersections(double *new_x, double *new_y, double rotation);
void check_intersections(void);


#endif