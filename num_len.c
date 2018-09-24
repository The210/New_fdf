/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:36:12 by dhorvill          #+#    #+#             */
/*   Updated: 2018/06/05 17:36:13 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			num_len(char *map, char c)
{
	int i[3];
	int sym;

	i[0] = 0;
	i[1] = 0;
	sym = 0;
	i[2] = 0;
	map = ft_strtrimc(map, ' ');
	while (map[i[0]])
	{
		while (map[i[0]] && map[i[0]] != c)
		{
			sym = 1;
			i[0]++;
			i[1] = 1;
		}
		while (map[i[0]] && map[i[0]] == c)
		{
			i[2] += sym;
			sym = 0;
			i[0]++;
		}
	}
	ft_strdel(&map);
	return (i[2] + i[1]);
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
