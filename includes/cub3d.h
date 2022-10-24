/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:24:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/18 14:39:02 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h> 
# include <X11/X.h> 
# include <math.h>

# define PI 3.1415926535
# define DG 0.0174533
# define MINI_MAP_SIZE 64
# define WINDOW_WIDTH 320
# define WINDOW_HEIGHT 200

# define PLAYER_SIZE 64
# define BACKGROUND_SIZE 600
# define WALL_SIZE 64
# define DIR_SIZE 32

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ray
{
	t_img	img;
	float	x;
	float	y;
	float	h_x;
	float	h_y;
	float	v_x;
	float	v_y;
	int		pixel;
	float	x_texture;
	float	distance_to_wall;
	float	line_height;
	float	line_o;
	float	rotation;
	float	diference_angle;
	int		p;
}				t_ray;

typedef struct s_player
{
	t_img	img;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	dir_x;
	float	dir_y;
	float	test_x;
	float	test_y;
	float	rotation;
	t_img	dir_img;
}				t_player;

typedef struct s_data
{
	char		*map_string;
	char		**map_array;
	int			player_nbs;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			floor_color;
	int			ceiling_color;
	int			walls_nbs;
	float		**walls_position;
	void		*mlx;
	t_img		txt_img1;
	t_img		txt_img2;
	t_img		txt_img3;
	t_img		txt_img4;
	int			texture1[64][64];
	int			texture2[64][64];
	int			texture3[64][64];
	int			texture4[64][64];
	void		*win_ptr;
	t_ray		rays[326];
	t_img		txt_img[4];
	t_player	player;
	t_img		game_img;
	t_img		line_img;
	t_img		mm_wall_img;
	t_img		mm_bg_img;
	t_img		test_img;
	int			texture_ok;
	float		tan;
	float		rx;
	float		ry;
	float		yo;
	float		xo;
	size_t		tmp_i;
}				t_data;

void	parse_map(t_data *data);
//Arguments parsing
int		validate_map_extension(char *map_name);
int		validate_save_argument(char *save_param);
int		validate_arguments(int argc, char **argv);
//Get textures path
int		get_no_texture(char *no_path, t_data *data);
int		get_so_texture(char *so_path, t_data *data);
int		get_ea_texture(char *ea_path, t_data *data);
int		get_we_texture(char *we_path, t_data *data);
//set and validate rgb colors
int		get_floor_color(char *rgb, t_data *data);
int		get_ceiling_color(char *rgb, t_data *data);
int		validate_rgb_colors(t_data *data, char **rgbs);
//print a new error msg on stderr and returns 1
int		msg_error(char *error);
//error or close
void	free_mlx_core(t_data *data);
void	free_matrix(void **matrix);
//parse_map
void	handle_error(t_data *data, char *error_message);
void	check_valid_space_sorround_by_wall(t_data *data, char *line,
			char *up_line, char *down_line);
char	**normalize_map(char **map_array);
void	iterate_map_array(t_data *data);
//mlx
void	new_window(t_data *data);
int		render_loop(t_data *data);
void	handle_hooks(t_data *data);
//moviments
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	rotate_right(t_data *data);
void	rotate_left(t_data *data);
//draw
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_square(t_img *img, int color, int x, int y);
void	init_imgs(t_data *data);
void	draw_minimap(t_data *data);
//math
float	distance_btw_two_points(float x1, float y1, float x2, float y2);
//ray_cast
void	save_walls_position(t_data *data);
void	check_intersections(t_data *data);
void	draw_3d_world(t_data *data);
int		img_pix_get(t_img *img, int x, int y);
void	check_intersections_h(t_data *data, float *new_x,
			float *new_y, float rotation);
void	check_intersections_v(t_data *data, float *new_x,
			float *new_y, float rotation);
void	save_texture_pixels(t_data *data);
//map
int		biggest_line_size(char **map_array);
int		lines_amount(char **map_array);
void	init_minimap_imgs(t_data *data);
void	init_img(t_data *data, t_img *img, int height, int width);
//utils_ray_cast
void	find_intersection_point_h(t_data *data,
			float *new_x, float *new_y, int loop);
void	find_intersection_point_v(t_data *data,
			float *new_x, float *new_y, int loop);
int		get_texture_pixel(t_data *data, int x, int y, int pos);
void	more_free(t_data *data);
void	free_matrix_char(char **matrix);
void	set_wall_positions(t_data *data, int height, int width, int *z);
void	save_walls_position(t_data *data);
void	get_player_first_position(t_data *data);
int		check_type(char *string, t_data *data);
char	*validate_map_params(int map, t_data *data);
void	get_map_string(t_data *data, int map);
int		color_util(int index, char ***rgb_array, int **int_array);
int		is_valid_rgb_value(char *rgb, char **rgbs);

#endif
