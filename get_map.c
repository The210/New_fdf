/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:14:54 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/30 17:14:55 by dhorvill         ###   ########.fr       */
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
