/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:09:59 by dduarte-          #+#    #+#             */
/*   Updated: 2023/09/05 09:20:40 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(char const *str)
{
	int i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}
int	ft_controws(t_game *game)
{
	char *str;
	int 	i;
	
	i = 0;
	while(1)
	{
		str = get_next_line(game->fd)
		if (!str)
			break;
		free(str);
		i++;
	}
	free(str);
	return (i);
}