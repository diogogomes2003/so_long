# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 08:32:53 by dduarte-          #+#    #+#              #
#    Updated: 2023/11/09 14:50:21 by dduarte-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = srcs/so_long.c srcs/check_errors.c srcs/create_map.c srcs/libx.c \
		srcs/clean_and_exit.c srcs/utils.c srcs/moves.c

OBJ = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx
LIBFT = -L ${LIBFT_PATH} -lft
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

all: ${NAME}

$(NAME): ${OBJ}
	${MAKE} ${LIBFT_PATH}
	${MAKE} ${MLX_PATH}
	${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}


clean:
	${MAKE} ${LIBFT_PATH} clean
	${MAKE} ${MLX_PATH} clean
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT: