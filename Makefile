# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 08:32:53 by dduarte-          #+#    #+#              #
#    Updated: 2023/11/09 15:45:37 by dduarte-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/so_long.c srcs/utils.c srcs/libx.c srcs/create_map.c srcs/clean_and_exit.c srcs/check_errors.c srcs/moves.c

NAME = so_long

OBJS = ${SRC:.c=.o}

RM = rm -f

FLAGS = -Wall -Wextra -Werror -g

MAKE = make -C

LIBFT_PATH = lib/libft

MLX_PATH = lib/mlx

LIBFT = -L ${LIBFT_PATH} -lft

MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

all: ${NAME}

$(NAME): ${OBJS}
				${MAKE} ${LIBFT_PATH}
				${MAKE} ${MLX_PATH}
				cc ${FLAGS} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}
				
clean:
				${MAKE} ${LIBFT_PATH} clean
				${MAKE} ${MLX_PATH} clean
				${RM} ${OBJS}

fclean: clean
				${MAKE} ${LIBFT_PATH} fclean
				${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT: