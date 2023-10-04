/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:34:22 by dduarte-          #+#    #+#             */
/*   Updated: 2023/10/04 13:01:01 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_mlx(t_game *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		exit_error(so_long, "Failed to initialize mlx.");
	so_long->win = mlx_new_window(so_long->mlx, so_long->columns * SIZE, \
									so_long->rows * SIZE, "so_long");
	if (!so_long->win)
		exit_error(so_long, "Failed to create window.");
}

void	load_sprites(t_game *so_long)
{
	so_long->sprites = malloc(SPRITES * sizeof(t_sprites));
	if (!so_long->sprites)
		exit_error(so_long, "Failed to allocate memory on sprites.");
	so_long->sprites[W1].img = mlx_xpm_file_to_image(so_long->mlx, PWALL,
			&(so_long->sprites[W1].width), &(so_long->sprites[W1].height));
	so_long->sprites[S1].img = mlx_xpm_file_to_image(so_long->mlx, PSPACES,
			&(so_long->sprites[S1].width), &(so_long->sprites[S1].height));
	so_long->sprites[C1].img = mlx_xpm_file_to_image(so_long->mlx, PCOIN,
			&(so_long->sprites[C1].width), &(so_long->sprites[C1].height));
	so_long->sprites[E1].img = mlx_xpm_file_to_image(so_long->mlx, PEXIT,
			&(so_long->sprites[E1].width), &(so_long->sprites[E1].height));
	so_long->sprites[P1].img = mlx_xpm_file_to_image(so_long->mlx, PPLAYER,
			&(so_long->sprites[P1].width), &(so_long->sprites[P1].height));
}

void	render_map(t_game *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (++y < so_long->rows)
	{
		x = -1;
		while (++x < so_long->columns)
			render_positions(so_long, x, y);
	}
}

void	render_positions(t_game *so_long, int x, int y)
{
	if (so_long->map[y][x] == WALL)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sprites[W1].img, so_long->sprites[W1].width * x, \
								so_long->sprites[W1].height * y);
	else if (so_long->map[y][x] == COIN)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sprites[C1].img, so_long->sprites[C1].width * x, \
								so_long->sprites[C1].height * y);
	else if (so_long->map[y][x] == EXIT)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sprites[E1].img, so_long->sprites[E1].width * x, \
								so_long->sprites[E1].height * y);
	else if (so_long->map[y][x] == SPACE)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sprites[S1].img, so_long->sprites[S1].width * x, \
								so_long->sprites[S1].height * y);
	else if (so_long->map[y][x] == PLAYER)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sprites[P1].img, so_long->sprites[P1].width * x, \
								so_long->sprites[P1].height * y);
}
