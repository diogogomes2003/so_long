/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:59:39 by diodos-s          #+#    #+#             */
/*   Updated: 2023/11/09 15:59:00 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <fcntl.h>

# define SIZE		50
# define SPRITES	5

# define FW1		"assets/sprites/wall.xpm"
# define FS1		"assets/sprites/spaces.xpm"
# define FC1		"assets/sprites/coin.xpm"
# define FE1		"assets/sprites/exit.xpm"
# define FP1		"assets/sprites/player.xpm"

# define ON_KEYPRESS 2
# define ON_CLOSE 17

# define ESC		65307
# define W			119
# define A			97
# define S			115
# define D			100
# define UP			65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363

# define W1 0
# define S1 1
# define C1 2
# define E1 3
# define P1 4

typedef enum e_mask
{
	KEYPRESS_MASK	= (1L << 0),
	CLOSE_MASK		= (1L << 17)
}	t_mask;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}			t_sprite;

typedef struct s_game
{
	t_sprite	*sprites;
	t_position	prev;
	t_position	curr;
	void		*mlx;
	void		*win;
	char		**map;
	int			rows;
	int			cols;
	int			moves;
	int			player;
	int			total_coins;
	int			coins;
	int			exit;
}	t_game;

int		check_key(int key, t_game *so_long);
void	create_map(t_game *so_long, char *map_file);
void	launch_mlx(t_game *so_long);
void	load_sprites(t_game *so_long);
void	render_map(t_game *so_long);
void	render_position(t_game *so_long, int x, int y);
int		return_msg(t_game *so_long);
int		flood_fill(int total_coins, int y, int x, char **test_map);
int		quit_game(t_game *so_long);
int		exit_error(t_game *so_long, char *msg);
void	check_map(t_game *so_long);
void	clean_test_map(char **test_map);
void	clean_game(t_game *so_long);
#endif