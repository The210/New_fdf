/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:11:05 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/30 17:17:49 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			num_len(char *map, char c)
{
	int i;
	int sym;
	int count;

	i = 0;
	sym = 0;
	count = 0;
	map = ft_strtrimc(map, ' ');
	while (map[i])
	{
		while (map[i] && map[i] != c)
		{
			sym = 1;
			i++;
		}
		while (map[i] && map[i] == c)
		{
			count += sym;
			sym = 0;
			i++;
		}
	}
	return (count + 1);
}

t_matrix	get_lines_init(char *argv, t_matrix matrix)
{
	int		i;
	int		length;
	char	*map;

	i = 0;
	length = 0;
	while (get_next_line(matrix.fd, &map) > 0)
	{
		length = num_len(map, ' ');
		ft_strdel(&map);
		i++;
	}
	close(matrix.fd);
	matrix.fd = open(argv, O_RDONLY);
	matrix.lines = i;
	if ((matrix.num_col = (int*)malloc(sizeof(int*) * (i + 1))) == 0)
	{
		matrix.flag = 1;
		return (matrix);
	}
	matrix.num_col[i] = '\0';
	return (matrix);
}

t_matrix	get_lines(char *argv, t_matrix matrix)
{
	int		i;
	int		length;
	int		max_length;
	char	*map;

	i = 0;
	matrix.num_num = 0;
	max_length = 0;
	matrix = get_lines_init(argv, matrix);
	while (get_next_line(matrix.fd, &map) > 0)
	{
		length = num_len(map, ' ');
		if (length > max_length)
			max_length = length;
		ft_strdel(&map);
		matrix.num_col[i] = length;
		matrix.num_num += length;
		i++;
	}
	close(matrix.fd);
	matrix.fd = open(argv, O_RDONLY);
	matrix.col = max_length;
	return (matrix);
}
