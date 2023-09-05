/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:03:26 by dduarte-          #+#    #+#             */
/*   Updated: 2023/09/05 09:56:04 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	

void	ft_initmap(t_game *game, char *mapname)
{
	game->fd = open(mapname, O_RDONLY);
	game->rows = ft_controws(game);
	close(game->fd);
	game->fd = open(mapname, O_RDONLY);
	game->map = ft_calloc(game->rows + 1, sizeof(char *));
	if(!game->map)
	{
		free(game->map);
		exit_error(game,"Couldn't open map");
	}
	ft_get_map(game);
	close(game->fd);
}