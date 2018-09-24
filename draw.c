/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:35:03 by dhorvill          #+#    #+#             */
/*   Updated: 2018/06/05 17:35:04 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		get_nbr(char *map)
{
	float	j;
	int		i;
	int		f;

	f = 1;
	j = 0;
	i = 0;
	if (map[i] == '-')
	{
		f = -1;
		i = 1;
	}
	while (map[i] == '+')
		i++;
	while (map[i])
	{
		j = j * 10 + map[i] - '0';
		i++;
	}
	return (j * f);
}

t_coord		map_2d(float z, t_coord point, t_matrix matrix)
{
	float tempx;
	float tempy;

	tempy = matrix.ky - (matrix.lines / 2);
	tempx = matrix.kx - matrix.col / 2;
	point.x = (matrix.matx1 * tempx + matrix.matx2 * tempy + matrix.matx3 * z)
		* (matrix.distance / (matrix.num_num / matrix.lines));
	point.y = (matrix.maty1 * tempx + matrix.maty2 * tempy + matrix.maty3 * z)
		* (matrix.distance / (matrix.num_num / matrix.lines));
	point.x += matrix.posx;
	point.y += matrix.posy;
	return (point);
}

void		draw_across(t_matrix matrix, t_coord point, t_coord next_point)
{
	matrix.ky = 0;
	matrix.counted = 0;
	while (matrix.ky < matrix.lines)
	{
		matrix.kx = 0;
		while (matrix.kx < matrix.num_col[matrix.ky] - 1)
		{
			point = map_2d((get_nbr(matrix.map[matrix.kx + matrix.counted]))
					* matrix.alt, point, matrix);
			matrix.kx++;
			next_point = map_2d(
					(get_nbr(matrix.map[matrix.kx + matrix.counted]))
					* matrix.alt, point, matrix);
			if (matrix.num_col[matrix.ky + 1] > matrix.kx
					|| (matrix.num_col[matrix.ky - 1]
						&& matrix.num_col[matrix.ky - 1] > matrix.kx))
				ft_draw_line2(point, next_point, matrix);
		}
		matrix.counted += matrix.kx != 0 ? matrix.kx + 1 : 0;
		matrix.ky++;
	}
}

void		draw_columns(t_matrix matrix, t_coord point, t_coord next_point)
{
	int indey;

	matrix.kx = 0;
	while (matrix.kx < matrix.col)
	{
		indey = matrix.kx;
		matrix.ky = 0;
		while (matrix.ky < matrix.lines - 1)
		{
			if (matrix.num_col[matrix.ky] > matrix.kx &&
					matrix.num_col[matrix.ky + 1] > matrix.kx)
			{
				point = map_2d((get_nbr(matrix.map[indey])) * matrix.alt,
						point, matrix);
				matrix.ky++;
				next_point = map_2d((get_nbr(matrix.map[indey + matrix.num_col
				[matrix.ky - 1]])) * matrix.alt, point, matrix);
				ft_draw_line2(point, next_point, matrix);
			}
			else
				matrix.ky++;
			indey += matrix.num_col[matrix.ky - 1];
		}
		matrix.kx++;
	}
}
