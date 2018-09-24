/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:35:22 by dhorvill          #+#    #+#             */
/*   Updated: 2018/06/08 22:42:14 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf(t_matrix matrix)
{
	t_coord	point;
	t_coord next_point;

	point.x = 0;
	point.y = 0;
	point.z = 0;
	next_point.x = 0;
	next_point.y = 0;
	next_point.z = 0;
	draw_across(matrix, point, next_point);
	draw_columns(matrix, point, next_point);
	mlx_put_image_to_window(matrix.mlx, matrix.win, matrix.img, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_matrix	matrix;

	if (ac != 2 || ((matrix.fd = open(av[1], O_RDONLY)) < 0) ||
	((matrix.map = (get_map(matrix.fd))) == NULL))
	{
		ft_putendl("Error: Read failed");
		return (0);
	}
	init_matrix(&matrix);
	matrix.av = av[1];
	close(matrix.fd);
	matrix.fd = open(av[1], O_RDONLY);
	matrix.mlx = mlx_init();
	matrix.win = mlx_new_window(matrix.mlx, 2000, 1400, "TrueFDF");
	matrix.img = mlx_new_image(matrix.mlx, 2000, 2000);
	matrix.img_string =
	(int*)mlx_get_data_addr(matrix.img, &(matrix.bpp),
	&(matrix.s_l), &(matrix.endian));
	matrix = get_lines(av[1], matrix);
	fdf(matrix);
	mlx_hook(matrix.win, 2, (1L << 0), interactive, (void *)&matrix);
	mlx_loop(matrix.mlx);
	ft_strdel(matrix.map);
	return (0);
}
