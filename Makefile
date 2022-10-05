# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 11:06:29 by mvieira-          #+#    #+#              #
#    Updated: 2022/10/05 12:05:18 by mvieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS_PATH = ./includes/
SRCS_PATH = ./srcs/
ERROR_PATH = error/
PARSE_MAP_PATH = parse_map/
MLX_UTILS_PATH = mlx_utils/
TEXTURES_PATH = path_textures/
MOVIMENTS_PATH = moviments/
RAY_CASTING_PATH = ray_casting/
CMD_PARSER_PATH = validate_arguments/
OBJS_PATH = ./objs/
LIBS_PATH = ./Libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I $(HEADERS_PATH)
RM = rm -f
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory
NAME = cub3D
SRC_FILES = main.c \
			$(RAY_CASTING_PATH)draw_map.c\
			$(RAY_CASTING_PATH)draw.c\
			$(RAY_CASTING_PATH)ray_cast.c\
			$(RAY_CASTING_PATH)using_img.c\
			$(MOVIMENTS_PATH)moviments.c\
			$(MOVIMENTS_PATH)rotation_moviments.c\
			$(MLX_UTILS_PATH)render_loop.c \
			$(MLX_UTILS_PATH)handle_mlx_hooks.c \
			$(MLX_UTILS_PATH)new_window.c \
			$(PARSE_MAP_PATH)map_utils.c \
			$(PARSE_MAP_PATH)iterate_map.c \
			$(PARSE_MAP_PATH)normalize_map.c \
			$(PARSE_MAP_PATH)parse_map.c \
			$(ERROR_PATH)handle_errors.c \
			$(ERROR_PATH)msg_error.c \
			$(CMD_PARSER_PATH)validate_arguments.c \
			$(CMD_PARSER_PATH)validate_map_extension.c \
			$(CMD_PARSER_PATH)validate_save_argument.c \
			$(TEXTURES_PATH)index.c \
			$(TEXTURES_PATH)colors.c

LIBFT_A = $(LIBS_PATH)libft.a 
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

all: $(NAME)

$(LIBFT_A):
	@cd $(LIBS_PATH) && $(MAKE_NOPRINT)
	
$(NAME): $(LIBFT_A) $(OBJECTS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_A) -lm -lmlx -lXext -lX11

#-lmlx -lXext -lX11 

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(MKDIR) $(OBJS_PATH)$(ERROR_PATH)
	@$(MKDIR) $(OBJS_PATH)$(CMD_PARSER_PATH)
	@$(MKDIR) $(OBJS_PATH)$(TEXTURES_PATH)
	@$(MKDIR) $(OBJS_PATH)$(PARSE_MAP_PATH)
	@$(MKDIR) $(OBJS_PATH)$(MLX_UTILS_PATH)
	@$(MKDIR) $(OBJS_PATH)$(MOVIMENTS_PATH)
	@$(MKDIR) $(OBJS_PATH)$(RAY_CASTING_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ 

bonus: all

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE_NOPRINT) clean -C $(LIBS_PATH)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_NOPRINT) fclean -C $(LIBS_PATH)

re: fclean all

.PHONY: all run clean fclean re 