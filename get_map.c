/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:18:35 by smerelo           #+#    #+#             */
/*   Updated: 2018/03/30 14:49:36 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_map(int fd)
{
	char	*map;
	char	*buff;
	char	**map2;

	map = ft_strnew(1);
	while (get_next_line(fd, &buff) > 0)
	{
		map = ft_strjoin2(map, buff);
		ft_strdel(&buff);
	}
	if ((map2 = ft_strsplit(map, ' ')) == NULL)
		return (0);
	return (map2);
}
