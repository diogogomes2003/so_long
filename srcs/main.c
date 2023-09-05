/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:18:25 by dduarte-          #+#    #+#             */
/*   Updated: 2023/09/05 09:19:04 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(t_game *game, char *msg)
{
	clean_game(game);
	ft_putstr_fd("Erro\n", 2);
	ft_putstr_fd(msg"\n", 2);
	exit(EXIT_FAILURE);
}

int	checkfilename(char *s)
{
	int	i;

	i = 0;
	i = ft_strlen(s);
	if (!ft_strnstr(s + i - 4, ".ber", 4))
	{
		exit_error(NULL, "Wrong map format, try .ber");
		return (0);
	}
	return (1);
}

void	launch_game(char *file)
{
	t_game	game;

	bzero(&game, sizeof(t_game));
	ft_initmap(&game, file);
	check_map(&game);
	launch_window(&game);
	ft_getsprites(&game);
	make_map(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, check_key, &game);
	mlx_hook(game.win, DestroyNotify, 0, quit_game, &game);
	mlx_loop(game.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Wrong number of arguments.");
		return (0);
	}
	checkfilename(av[1]);
	launch_game(av[1]);
	return (0);
}
