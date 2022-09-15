# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 20:29:14 by mvieira-          #+#    #+#              #
#    Updated: 2022/09/15 12:55:41 by mvieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	./ft_bzero.c ft_isalnum.c ft_isalpha.c \
				ft_isdigit.c ft_isprint.c ft_memcpy.c \
				ft_memset.c ft_strlen.c ft_isascii.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_memchr.c ft_memcmp.c \
				ft_strncmp.c ft_strnstr.c ft_atoi.c \
				ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_printf.c \
				write_input.c \
				utils.c \
				write_string.c \
				write_integer.c \
				write_unsigned_integer.c \
				write_hex.c \
				itoa_base.c \
				write_hex_upper.c \
				write_pointer.c 

H_SRC		=	../includes/libft.h

OBJS		=	${SRC:.c=.o}

NAME		=	libft.a

FLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

.c.o:
	@cc ${FLAGS} -c $< -o ${<:.c=.o} 

$(NAME):	${OBJS} ${H_SRC}
			@ar -rcs $@ $^

all: ${NAME}

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re