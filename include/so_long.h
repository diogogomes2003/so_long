/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:42:41 by dduarte-          #+#    #+#             */
/*   Updated: 2023/10/04 13:06:26 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libs
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

// Sprites
# define PWALL "./assets/sprites/wall.xpm"
# define PSPACES "./assets/sprites/spaces.xpm"
# define PPLAYER "./assets/sprites/player.xpm"
# define PEXIT "./assets/sprites/exit.xpm"
# define PCOIN "./assets/sprites/coin.xpm"
# define TILES "01CEP"
# define SPACE	'0'
# define WALL	'1'
# define COIN	'C'
# define EXIT	'E'
# define PLAYER	'P'
# define SIZE 32
# define SPRITES 5
# define W1 0
# define S1 1
# define C1 2
# define E1 3
# define P1 4

// keys 
# define ON_KEYPRESS 2
# define ON_CLOSE 17
# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363

typedef enum e_mask
{
	KEYPRESS_MASK	= (1L << 0),
	CLOSE_MASK		= (1L << 17)
}	t_mask;

// structs
typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct t_sprite
{
	void	*img;
	int		height;
	int		width;
}			t_sprites;

typedef struct s_game
{
	t_sprites	*sprites;
	t_pos		prev;
	t_pos		curr;
	void		*mlx;
	void		*win;
	char		**map;
	int			rows;
	int			columns;
	int			moves;
	int			player;
	int			total_coins;
	int			coins;
	int			exit;
}	t_game;

// map[rows][columns]
// so_long.c 
int		check_file_extension(char *str);
void	launch_game(char *map_file);
// create_map.c
void	create_map(t_game *so_long, char *map_file);
void	map_rows(t_game *so_long, char *map_file);
void	read_map(t_game *so_long, int fd);
// check_map.c
int	check_format(t_game *so_long);
int	check_walls(t_game *so_long);
int	check_paths(t_game *so_long);
int	check_sprites(t_game *so_long);
void	check_map(t_game *so_long);
// libx.c
void	launch_mlx(t_game *so_long);
void	load_sprites(t_game *so_long);
void	render_map(t_game *so_long);
void	render_positions(t_game *so_long, int x, int y);
// utils.c
int	return_msg(t_game *so_long);
int	flood_fill(int total_coins, int cur_y, int cur_x, char **test_map);
int	quit_game(t_game *so_long);
int	exit_error(t_game *so_long, char *msg);
// moves.c
void	move_player(t_game *so_long);
void	check_move(t_game *so_long, int key);
int	check_key(int key, t_game *so_long);
// clean_and_exit.c
void	clean_map_test(char **test_map);
void	clean_sprites(t_game *so_long);
void	clean_map(t_game *so_long);
void	clean_game(t_game *so_long);

#endif