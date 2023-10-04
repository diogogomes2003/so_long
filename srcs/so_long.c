/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:18:25 by dduarte-          #+#    #+#             */
/*   Updated: 2023/10/04 11:41:40 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_game(char *map_file)
{
	t_game	so_long;

	ft_bzero(&so_long, sizeof(t_game));
	create_map(&so_long, map_file);
	check_map(&so_long);
	launch_mlx(&so_long);
	load_sprites(&so_long);
	render_map(&so_long);
	mlx_hook(so_long.win, ON_KEYPRESS, KEYPRESS_MASK, check_key, &so_long);
	mlx_hook(so_long.win, ON_CLOSE, CLOSE_MASK, quit_game, &so_long);
	mlx_loop(so_long.mlx);
}

int	check_file_extension(char *str)
{
	if (ft_strnstr(str + ft_strlen(str) - 4, ".ber", 4))
		return (EXIT_SUCCESS);
	else
	{
		ft_printf("Error, the file extension need to be .ber");
		return (EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Wrong number of arguments.\n");
		return (0);
	}
	check_file_extension(av[1]);
	launch_game(av[1]);
	return (0);
}
