/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:49:19 by smerelo           #+#    #+#             */
/*   Updated: 2018/03/30 15:44:06 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	mdy(t_coord point, t_coord next_point, t_matrix matrix)
{
	matrix.m = matrix.dy / matrix.dx;
	matrix.pb = point.y - matrix.m * point.x;
	while (point.x != next_point.x)
	{
		matrix.intm = round(matrix.m * point.x + matrix.pb);
		if (point.x < 2000 && matrix.intm < 1399
		&& point.x >= 0 && matrix.intm >= 0)
			matrix.img_string[matrix.intm * 2000 + point.x] = matrix.color;
		point.x += matrix.sx;
	}
	return (matrix);
}

t_matrix	mdx(t_coord point, t_coord next_point, t_matrix matrix)
{
	matrix.m = matrix.dx / matrix.dy;
	matrix.pb = point.x - matrix.m * point.y;
	while (point.y != next_point.y)
	{
		matrix.intb = round(matrix.m * point.y + matrix.pb);
		if (matrix.intb < 2000 && point.y < 1399
		&& matrix.intb >= 0 && point.y >= 0)
			matrix.img_string[point.y * 2000 + matrix.intb] = matrix.color;
		point.y += matrix.sy;
	}
	return (matrix);
}

int			ft_draw_line2(t_coord point, t_coord next_point, t_matrix matrix)
{
	if (point.x == next_point.x && point.y == next_point.y)
	{
		if (point.x < 2000 && point.y < 1399 && point.x >= 0 && point.y >= 0)
			matrix.img_string[point.y * 2000 + point.x] = matrix.color;
		return (0);
	}
	matrix.dx = next_point.x - point.x;
	matrix.dy = next_point.y - point.y;
	matrix.sx = (matrix.dx < 0) ? -1 : 1;
	matrix.sy = (matrix.dy < 0) ? -1 : 1;
	if (fabsf(matrix.dy) < fabsf(matrix.dx))
		matrix = mdy(point, next_point, matrix);
	else
		matrix = mdx(point, next_point, matrix);
	if (next_point.x < 2000 && next_point.y < 1399 &&
			next_point.x >= 0 && next_point.y >= 0)
		matrix.img_string[next_point.y * 2000 + next_point.x] = matrix.color;
	return (0);
}
