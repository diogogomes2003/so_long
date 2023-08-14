# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 08:32:53 by dduarte-          #+#    #+#              #
#    Updated: 2023/08/14 09:40:49 by dduarte-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = srcs/main.c srcs/make_map.c srcs/utils.c srcs/moves.c srcs/sprites.c \
		srcs/check_map.c srcs/clean_game.c

OBJ = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
MLX_PATH = mlx
LIBFT = -L ${LIBFT_PATH} -lft
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
	${MAKE} ${LIBFT_PATH}
	${MAKE} ${MLX_PATH}
	${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}

all: ${NAME}

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