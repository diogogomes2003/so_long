/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:42:41 by dduarte-          #+#    #+#             */
/*   Updated: 2023/09/05 10:21:32 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <fcntl.h>
# define WALL "./assets/sprites/WALL.xpm"
# define SPACES "./assets/sprites/SPACES.xpm"
# define PLAYER "./assets/sprites/CharSprites/Player.xpm"
# define EXIT "./assets/sprites/Exit.xpm"
# define COIN "./assets/sprites/coin.xpm"
# define TILES "01CEP"
# define SIZE 45

# define MLX_ERROR "ERROR : mlx failed."
# define MLX_WIN_ERROR "ERROR : win failed."
# define SPRITES 5

typedef enum e_index
{
	Wall,
	Spaces,
	Coin,
	Exit,
	Player,
}		t_id;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_sprites
{
	void	*img;
	int		height;
	int		width;
}			t_sprites;

typedef enum e_key
{
	ESC		= 65307,
	W		= 119,
	A		= 97,
	S		= 115,
	D		= 100,
	UP		= 65362,
	DOWN	= 65364,
	LEFT	= 65361,
	RIGHT	= 65363,
}			t_key;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_sprites	*sp;
	t_pos		next;
	t_pos		curr;
	int			fd;
	int			columns;
	int			rows;
	char		**map;
	int			coins;
	int			count;
	int			exit;
	int			player;	
}	t_game;

// Main func
int		checkfilename(char *s);
int		exit_error(t_game *game, char *msg);
void	launch_game(char *file);
// make_map func
void	ft_initmap(t_game *game, char *mapname);
void	make_map(t_game *game);
void	ft_get_map(t_game *game);
// utils func
int		ft_len(char const *str);
int		ft_controws(t_game *game);

#endif