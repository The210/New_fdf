/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_interactive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:15:17 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/30 17:15:18 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*mk_image(t_matrix matrix)
{
	mlx_destroy_image(matrix.mlx, matrix.img);
	matrix.img = mlx_new_image(matrix.mlx, 2000, 2000);
	matrix.img_string = (int*)mlx_get_data_addr(matrix.img,
			&(matrix.bpp), &(matrix.s_l), &(matrix.endian));
	return (matrix.img);
}

void		movement(int keycode, t_matrix *matrix)
{
	if (keycode == 13 || keycode == 12 || keycode == 14)
		matrix->posy -= 20 * matrix->v;
	if (keycode == 1 || keycode == 6 || keycode == 8)
		matrix->posy += 20 * matrix->v;
	if (keycode == 0 || keycode == 12 || keycode == 6)
		matrix->posx -= 20 * matrix->v;
	if (keycode == 2 || keycode == 8 || keycode == 14)
		matrix->posx += 20 * matrix->v;
}

void		interaction(int keycode, t_matrix *matrix)
{
	if (keycode == 82)
		*matrix = init_matrix(matrix);
	if (keycode == 69)
		matrix->alt += 0.05;
	if (keycode == 78)
		matrix->alt -= 0.05;
	if (keycode == 116)
		matrix->distance += 150;
	if (keycode == 121)
	{
		if (matrix->distance >= 151)
			matrix->distance -= 150;
	}
}

void		colors(int keycode, t_matrix *matrix)
{
	if (keycode == 18)
		matrix->color = 0xffffff;
	if (keycode == 19)
		matrix->color = 0xa52121;
	if (keycode == 20)
		matrix->color = 0xddda2c;
	if (keycode == 21)
		matrix->color = 0x75bf41;
	if (keycode == 23)
		matrix->color = 0x395670;
	if (keycode == 22)
		matrix->color = 0x8d3daa;
}

int			interactive(int keycode, t_matrix *matrix)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 258)
		matrix->v += 0.5;
	if (keycode == 257)
		matrix->v -= 0.5;
	rotation(keycode, matrix);
	movement(keycode, matrix);
	interaction(keycode, matrix);
	colors(keycode, matrix);
	matrix->img = mk_image(*matrix);
	close(matrix->fd);
	matrix->fd = open(matrix->av, O_RDONLY);
	fdf(*matrix);
	return (0);
}
