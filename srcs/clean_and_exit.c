/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:36:36 by dduarte-          #+#    #+#             */
/*   Updated: 2023/11/09 14:56:43 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	clean_test_map(char **test_map)
{
	size_t	i;

	i = 0;
	if (!test_map)
		return ;
	while (test_map[i])
		free(test_map[i++]);
	free(test_map);
}

void	clean_sprites(t_game *so_long)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		mlx_destroy_image(so_long->mlx, so_long->sprites[i].img);
	free(so_long->sprites);
}

void	clean_map(t_game *so_long)
{
	size_t	i;

	i = 0;
	if (!so_long->map)
		return ;
	while (so_long->map[i])
		free(so_long->map[i++]);
	free(so_long->map);
}

void	clean_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
		clean_map(so_long);
	if (so_long->sprites)
		clean_sprites(so_long);
	if (so_long->win)
		mlx_destroy_window(so_long->mlx, so_long->win);
	if (so_long->mlx)
		mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
}