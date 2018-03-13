/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 18:03:42 by smerelo           #+#    #+#             */
/*   Updated: 2018/02/18 22:15:06 by smerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_draw_line2(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	float dx;
	int sx;
	float dy;
	int sy;
	float m;
	float b;

	if (x0 == x1 && y0 == y1)
	{
		mlx_pixel_put(mlx, win, x0, y0, 0x00FFFFFF);
		return (0);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	sx = (dx < 0) ? -1 : 1;
	sy = (dy < 0) ? -1 : 1;

	if (fabsf(dy) < fabsf(dx))
	{
		m = dy / dx;
		b = y0 - m * x0;
		while (x0 != x1)
		{
			mlx_pixel_put(mlx, win, x0, round(m * x0 + b), 0x00FFFFFF);
			x0 += sx;
		}
	}
	else
	{
		m = dx / dy;
		b = x0 - m * y0;
		while (y0 != y1)
		{
			mlx_pixel_put(mlx, win, round(m * y0 +b), y0, 0x00FFFFFF);
			y0 += sy;
		}
	}
	mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
	return (0);
}
