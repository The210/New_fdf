/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:35:33 by dhorvill          #+#    #+#             */
/*   Updated: 2018/06/26 13:12:31 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_map(int fd)
{
	char	*map;
	char	*buff;
	int		i;
	char	**map2;

	map = ft_strnew(1);
	while ((i = get_next_line(fd, &buff)) > 0)
	{
		map = ft_strjoin2(map, buff);
		ft_strdel(&buff);
	}
	if (i == -1)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		if ((map[i] < '0' || map[i] > '9') && map[i] != ' '
			&& map[i] != '-' && map[i] != '+')
			return (NULL);
	}
	if ((map2 = ft_strsplit(map, ' ')) == NULL)
		return (0);
	i = -1;
	ft_strdel(&map);
	return (map2[0] == NULL ? NULL : map2);
}
