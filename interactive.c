/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 22:08:28 by smerelo           #+#    #+#             */
/*   Updated: 2018/03/05 04:20:45 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*mk_image(t_matrix matrix)
{
	mlx_destroy_image(matrix.mlx, matrix.img);
	matrix.img = mlx_new_image(matrix.mlx, 2000, 2000);
	matrix.img_string = (int*)mlx_get_data_addr(matrix.img, &(matrix.bpp), &(matrix.s_l), &(matrix.endian));
	return(matrix.img);
}

t_matrix	init_temps(t_matrix matrix)
{
	matrix.PMatx1 = matrix.Matx1;
	matrix.PMatx2 = matrix.Matx2;
	matrix.PMatx3 = matrix.Matx3;
	matrix.PMaty1 = matrix.Maty1;
	matrix.PMaty2 = matrix.Maty2;
	matrix.PMaty3 = matrix.Maty3;
	matrix.PMatz1 = matrix.Matz1;
	matrix.PMatz2 = matrix.Matz2;
	matrix.PMatz3 = matrix.Matz3;
	return (matrix)
}

int	interactive(int	keycode, t_matrix *matrix)
{
	if (keycode == 53)
		exit(0);
	ft_putnbrl(keycode);
	if(keycode == 258)
		matrix->v += 0.1;
	if (keycode == 257)
		matrix->v -= 0.1;
	if (keycode == 91) // 8 rotate x
	{
		matrix->thetax += 3.14/360 * matrix->v;
		matrix->Matx1 = 1;
		matrix->Maty2 = cos(matrix->thetax);
		matrix->Maty3 = -sin(matrix->thetax);
		matrix->Matz2 = sin(matrix->thetax);
		matrix->Matz3 = cos(matrix->thetax);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 84) // 2 rotate x
	{
		matrix->thetax -= 3.14/360 * matrix->v;
		matrix->Matx1 = 1;
		matrix->Maty2 = cos(matrix->thetax);
		matrix->Maty3 = -sin(matrix->thetax);
		matrix->Matz2 = sin(matrix->thetax);
		matrix->Matz3 = cos(matrix->thetax);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 88) //6
	{
		matrix->thetay += 3.14/360 * matrix->v;
		matrix->Maty2 = 1;
		matrix->Matx1 = cos(matrix->thetay);
		matrix->Matx3 = sin(matrix->thetay);
		matrix->Matz1 = -sin(matrix->thetay);
		matrix->Matz3 = cos(matrix->thetay);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);


	}
	if (keycode == 86) //4
	{
		matrix->thetay -= 3.14/360 * matrix->v;
		matrix->Maty2 = 1;
		matrix->Matx1 = cos(matrix->thetay);
		matrix->Matx3 = sin(matrix->thetay);
		matrix->Matz1 = -sin(matrix->thetay);
		matrix->Matz3 = cos(matrix->thetay);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 89) //7
	{
		matrix->thetaz += 3.14/360 * matrix->v;
		matrix->Matz3 = 1;
		matrix->Matx1 = cos(matrix->thetaz);
		matrix->Maty1 = sin(matrix->thetaz);
		matrix->Matx2 = -sin(matrix->thetaz);
		matrix->Maty2 = cos(matrix->thetaz);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 13)//w
	{
		matrix->b -= 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 0)//a
	{
		matrix->a -= 0.40 *matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 12)//q
	{
		matrix->b -= 0.40 * matrix->v;
		matrix->a -= 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 8)//c
	{
		matrix->b += 0.40 * matrix->v;
		matrix->a += 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 1)//s
	{
		matrix->b += 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 6)//z
	{
		matrix->b += 0.40 * matrix->v;
		matrix->a -= 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 14)//e
	{
		matrix->b -= 0.40 * matrix->v;
		matrix->a += 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 15)//r
	{
		matrix->c += 0.20 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 3)//f
	{
		matrix->c -= 0.20 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 2)//d
	{
		matrix->a += 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 69)//+
	{
		matrix->alt += 0.1;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if(keycode == 78)//-
	{
		matrix->alt -= 0.1;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
return (0);
}
