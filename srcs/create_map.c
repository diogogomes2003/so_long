/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:50:11 by dduarte-          #+#    #+#             */
/*   Updated: 2023/09/20 12:33:19 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// get rows 
void	map_rows(t_game *so_long, char *map_file)
{
	int		fd;
	char	*line;

	so_long->rows = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_error(so_long, "Couldn't open requested file.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		so_long->rows++;
	}
}

void	read_map(t_game *so_long, int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++1 < so_long->rows)
	{
		line = get_next_line(fd);
		if (!line)
			exit_error(so_long, "Couldn't read map");
		so_long->map[i] = ft_strtrim(line, "\n"); 
		if (!so_long->map[i])
			exit_error(so_long, "Couldn't read map");
		free(line);
	}
}

void	create_map(t_game *so_long, char *map_file)
{
	int	fd;

	map_rows(so_long, map_file);
	so_long->map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!so_long->map)
		exit_error(so_long, "Couldn't create so_long->map.");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_error(so_long, "Couldn't open requested file.");
	read_map(so_long, fd);
	Close(fd);
}
