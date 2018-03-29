/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_interactive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:12:54 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/29 16:29:38 by dhorvill         ###   ########.fr       */
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
	return (matrix);
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
		*matrix = init_temps(*matrix);
		matrix->TMatx1 = 1;
		matrix->TMatx2 = 0;
		matrix->TMatx3 = 0;
		matrix->TMaty1 = 0;
		matrix->TMatz1 = 0;
		matrix->TMaty2 = cos(matrix->thetax);
		matrix->TMaty3 = -sin(matrix->thetax);
		matrix->TMatz2 = sin(matrix->thetax);
		matrix->TMatz3 = cos(matrix->thetax);
		matrix->Matx1 = (matrix->PMatx1 * matrix->TMatx1) + (matrix->PMatx2 * matrix->TMaty1) + (matrix->PMatx3 * matrix->TMatz1);
		matrix->Maty1 = (matrix->PMaty1 * matrix->TMatx1) + (matrix->PMaty2 * matrix->TMaty1) + (matrix->PMaty3 * matrix->TMatz1);
		matrix->Matz1 = (matrix->PMatz1 * matrix->TMatx1) + (matrix->PMatz2 * matrix->TMaty1) + (matrix->PMatz3 * matrix->TMatz1);
		matrix->Matx2 = (matrix->PMatx1 * matrix->TMatx2) + (matrix->PMatx2 * matrix->TMaty2) + (matrix->PMatx3 * matrix->TMatz2);
		matrix->Maty2 = (matrix->PMaty1 * matrix->TMatx2) + (matrix->PMaty2 * matrix->TMaty2) + (matrix->PMaty3 * matrix->TMatz2);
		matrix->Matz2 = (matrix->PMatz1 * matrix->TMatx2) + (matrix->PMatz2 * matrix->TMaty2) + (matrix->PMatz3 * matrix->TMatz2);
		matrix->Matx3 = (matrix->PMatx1 * matrix->TMatx3) + (matrix->PMatx2 * matrix->TMaty3) + (matrix->PMatx3 * matrix->TMatz3);
		matrix->Maty3 = (matrix->PMaty1 * matrix->TMatx3) + (matrix->PMaty2 * matrix->TMaty3) + (matrix->PMaty3 * matrix->TMatz3);
		matrix->Matz3 = (matrix->PMatz1 * matrix->TMatx3) + (matrix->PMatz2 * matrix->TMaty3) + (matrix->PMatz3 * matrix->TMatz3);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 84) // 2 rotate x
	{
		*matrix = init_temps(*matrix);
		matrix->TMatx1 = 1;
		matrix->TMatx2 = 0;
		matrix->TMatx3 = 0;
		matrix->TMaty1 = 0;
		matrix->TMatz1 = 0;
		matrix->TMaty2 = cos(matrix->thetax);
		matrix->TMaty3 = sin(matrix->thetax);
		matrix->TMatz2 = -sin(matrix->thetax);
		matrix->TMatz3 = cos(matrix->thetax);
		matrix->Matx1 = (matrix->PMatx1 * matrix->TMatx1) + (matrix->PMatx2 * matrix->TMaty1) + (matrix->PMatx3 * matrix->TMatz1);
		matrix->Maty1 = (matrix->PMaty1 * matrix->TMatx1) + (matrix->PMaty2 * matrix->TMaty1) + (matrix->PMaty3 * matrix->TMatz1);
		matrix->Matz1 = (matrix->PMatz1 * matrix->TMatx1) + (matrix->PMatz2 * matrix->TMaty1) + (matrix->PMatz3 * matrix->TMatz1);
		matrix->Matx2 = (matrix->PMatx1 * matrix->TMatx2) + (matrix->PMatx2 * matrix->TMaty2) + (matrix->PMatx3 * matrix->TMatz2);
		matrix->Maty2 = (matrix->PMaty1 * matrix->TMatx2) + (matrix->PMaty2 * matrix->TMaty2) + (matrix->PMaty3 * matrix->TMatz2);
		matrix->Matz2 = (matrix->PMatz1 * matrix->TMatx2) + (matrix->PMatz2 * matrix->TMaty2) + (matrix->PMatz3 * matrix->TMatz2);
		matrix->Matx3 = (matrix->PMatx1 * matrix->TMatx3) + (matrix->PMatx2 * matrix->TMaty3) + (matrix->PMatx3 * matrix->TMatz3);
		matrix->Maty3 = (matrix->PMaty1 * matrix->TMatx3) + (matrix->PMaty2 * matrix->TMaty3) + (matrix->PMaty3 * matrix->TMatz3);
		matrix->Matz3 = (matrix->PMatz1 * matrix->TMatx3) + (matrix->PMatz2 * matrix->TMaty3) + (matrix->PMatz3 * matrix->TMatz3);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 88) //6
	{
		*matrix = init_temps(*matrix);
		matrix->TMaty2 = 1;
		matrix->TMaty1 = 0;
		matrix->TMaty3 = 0;
		matrix->TMatx2 = 0;
		matrix->TMatz2 = 0;
		matrix->TMatx1 = cos(matrix->thetay);
		matrix->TMatx3 = sin(matrix->thetay);
		matrix->TMatz1 = -sin(matrix->thetay);
		matrix->TMatz3 = cos(matrix->thetay);
		matrix->Matx1 = (matrix->PMatx1 * matrix->TMatx1) + (matrix->PMatx2 * matrix->TMaty1) + (matrix->PMatx3 * matrix->TMatz1);
		matrix->Maty1 = (matrix->PMaty1 * matrix->TMatx1) + (matrix->PMaty2 * matrix->TMaty1) + (matrix->PMaty3 * matrix->TMatz1);
		matrix->Matz1 = (matrix->PMatz1 * matrix->TMatx1) + (matrix->PMatz2 * matrix->TMaty1) + (matrix->PMatz3 * matrix->TMatz1);
		matrix->Matx2 = (matrix->PMatx1 * matrix->TMatx2) + (matrix->PMatx2 * matrix->TMaty2) + (matrix->PMatx3 * matrix->TMatz2);
		matrix->Maty2 = (matrix->PMaty1 * matrix->TMatx2) + (matrix->PMaty2 * matrix->TMaty2) + (matrix->PMaty3 * matrix->TMatz2);
		matrix->Matz2 = (matrix->PMatz1 * matrix->TMatx2) + (matrix->PMatz2 * matrix->TMaty2) + (matrix->PMatz3 * matrix->TMatz2);
		matrix->Matx3 = (matrix->PMatx1 * matrix->TMatx3) + (matrix->PMatx2 * matrix->TMaty3) + (matrix->PMatx3 * matrix->TMatz3);
		matrix->Maty3 = (matrix->PMaty1 * matrix->TMatx3) + (matrix->PMaty2 * matrix->TMaty3) + (matrix->PMaty3 * matrix->TMatz3);
		matrix->Matz3 = (matrix->PMatz1 * matrix->TMatx3) + (matrix->PMatz2 * matrix->TMaty3) + (matrix->PMatz3 * matrix->TMatz3);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 86) //4
	{
		*matrix = init_temps(*matrix);
		matrix->TMaty2 = 1;
		matrix->TMaty1 = 0;
		matrix->TMaty3 = 0;
		matrix->TMatx2 = 0;
		matrix->TMatz2 = 0;
		matrix->TMatx1 = cos(matrix->thetay);
		matrix->TMatx3 = -sin(matrix->thetay);
		matrix->TMatz1 = sin(matrix->thetay);
		matrix->TMatz3 = cos(matrix->thetay);
		matrix->Matx1 = (matrix->PMatx1 * matrix->TMatx1) + (matrix->PMatx2 * matrix->TMaty1) + (matrix->PMatx3 * matrix->TMatz1);
		matrix->Maty1 = (matrix->PMaty1 * matrix->TMatx1) + (matrix->PMaty2 * matrix->TMaty1) + (matrix->PMaty3 * matrix->TMatz1);
		matrix->Matz1 = (matrix->PMatz1 * matrix->TMatx1) + (matrix->PMatz2 * matrix->TMaty1) + (matrix->PMatz3 * matrix->TMatz1);
		matrix->Matx2 = (matrix->PMatx1 * matrix->TMatx2) + (matrix->PMatx2 * matrix->TMaty2) + (matrix->PMatx3 * matrix->TMatz2);
		matrix->Maty2 = (matrix->PMaty1 * matrix->TMatx2) + (matrix->PMaty2 * matrix->TMaty2) + (matrix->PMaty3 * matrix->TMatz2);
		matrix->Matz2 = (matrix->PMatz1 * matrix->TMatx2) + (matrix->PMatz2 * matrix->TMaty2) + (matrix->PMatz3 * matrix->TMatz2);
		matrix->Matx3 = (matrix->PMatx1 * matrix->TMatx3) + (matrix->PMatx2 * matrix->TMaty3) + (matrix->PMatx3 * matrix->TMatz3);
		matrix->Maty3 = (matrix->PMaty1 * matrix->TMatx3) + (matrix->PMaty2 * matrix->TMaty3) + (matrix->PMaty3 * matrix->TMatz3);
		matrix->Matz3 = (matrix->PMatz1 * matrix->TMatx3) + (matrix->PMatz2 * matrix->TMaty3) + (matrix->PMatz3 * matrix->TMatz3);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 92) //9
	{
		*matrix = init_temps(*matrix);
		matrix->TMatz3 = 1;
		matrix->TMatz2 = 0;
		matrix->TMatz1 = 0;
		matrix->TMatx3 = 0;
		matrix->TMaty3 = 0;
		matrix->TMatx1 = cos(matrix->thetaz);
		matrix->TMaty1 = sin(matrix->thetaz);
		matrix->TMatx2 = -sin(matrix->thetaz);
		matrix->TMaty2 = cos(matrix->thetaz);
		matrix->Matx1 = (matrix->PMatx1 * matrix->TMatx1) + (matrix->PMatx2 * matrix->TMaty1) + (matrix->PMatx3 * matrix->TMatz1);
		matrix->Maty1 = (matrix->PMaty1 * matrix->TMatx1) + (matrix->PMaty2 * matrix->TMaty1) + (matrix->PMaty3 * matrix->TMatz1);
		matrix->Matz1 = (matrix->PMatz1 * matrix->TMatx1) + (matrix->PMatz2 * matrix->TMaty1) + (matrix->PMatz3 * matrix->TMatz1);
		matrix->Matx2 = (matrix->PMatx1 * matrix->TMatx2) + (matrix->PMatx2 * matrix->TMaty2) + (matrix->PMatx3 * matrix->TMatz2);
		matrix->Maty2 = (matrix->PMaty1 * matrix->TMatx2) + (matrix->PMaty2 * matrix->TMaty2) + (matrix->PMaty3 * matrix->TMatz2);
		matrix->Matz2 = (matrix->PMatz1 * matrix->TMatx2) + (matrix->PMatz2 * matrix->TMaty2) + (matrix->PMatz3 * matrix->TMatz2);
		matrix->Matx3 = (matrix->PMatx1 * matrix->TMatx3) + (matrix->PMatx2 * matrix->TMaty3) + (matrix->PMatx3 * matrix->TMatz3);
		matrix->Maty3 = (matrix->PMaty1 * matrix->TMatx3) + (matrix->PMaty2 * matrix->TMaty3) + (matrix->PMaty3 * matrix->TMatz3);
		matrix->Matz3 = (matrix->PMatz1 * matrix->TMatx3) + (matrix->PMatz2 * matrix->TMaty3) + (matrix->PMatz3 * matrix->TMatz3);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 89) //7
	{
		*matrix = init_temps(*matrix);
		matrix->TMatz3 = 1;
		matrix->TMatz2 = 0;
		matrix->TMatz1 = 0;
		matrix->TMatx3 = 0;
		matrix->TMaty3 = 0;
		matrix->TMatx1 = cos(matrix->thetaz);
		matrix->TMaty1 = -sin(matrix->thetaz);
		matrix->TMatx2 = sin(matrix->thetaz);
		matrix->TMaty2 = cos(matrix->thetaz);
		matrix->Matx1 = (matrix->PMatx1 * matrix->TMatx1) + (matrix->PMatx2 * matrix->TMaty1) + (matrix->PMatx3 * matrix->TMatz1);
		matrix->Maty1 = (matrix->PMaty1 * matrix->TMatx1) + (matrix->PMaty2 * matrix->TMaty1) + (matrix->PMaty3 * matrix->TMatz1);
		matrix->Matz1 = (matrix->PMatz1 * matrix->TMatx1) + (matrix->PMatz2 * matrix->TMaty1) + (matrix->PMatz3 * matrix->TMatz1);
		matrix->Matx2 = (matrix->PMatx1 * matrix->TMatx2) + (matrix->PMatx2 * matrix->TMaty2) + (matrix->PMatx3 * matrix->TMatz2);
		matrix->Maty2 = (matrix->PMaty1 * matrix->TMatx2) + (matrix->PMaty2 * matrix->TMaty2) + (matrix->PMaty3 * matrix->TMatz2);
		matrix->Matz2 = (matrix->PMatz1 * matrix->TMatx2) + (matrix->PMatz2 * matrix->TMaty2) + (matrix->PMatz3 * matrix->TMatz2);
		matrix->Matx3 = (matrix->PMatx1 * matrix->TMatx3) + (matrix->PMatx2 * matrix->TMaty3) + (matrix->PMatx3 * matrix->TMatz3);
		matrix->Maty3 = (matrix->PMaty1 * matrix->TMatx3) + (matrix->PMaty2 * matrix->TMaty3) + (matrix->PMaty3 * matrix->TMatz3);
		matrix->Matz3 = (matrix->PMatz1 * matrix->TMatx3) + (matrix->PMatz2 * matrix->TMaty3) + (matrix->PMatz3 * matrix->TMatz3);
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 13)//w
	{
		matrix->b -= 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 0)//a
	{
		matrix->a -= 0.40 *matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 12)//q
	{
		matrix->b -= 0.40 * matrix->v;
		matrix->a -= 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 8)//c
	{
		matrix->b += 0.40 * matrix->v;
		matrix->a += 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 1)//s
	{
		matrix->b += 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 6)//z
	{
		matrix->b += 0.40 * matrix->v;
		matrix->a -= 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 14)//e
	{
		matrix->b -= 0.40 * matrix->v;
		matrix->a += 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 15)//r
	{
		matrix->c += 2 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 3)//f
	{
		matrix->c -= 2 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 2)//d
	{
		matrix->a += 0.40 * matrix->v;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 69)//+
	{
		matrix->alt += 0.05;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 78)//-
	{
		matrix->alt -= 0.05;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 126)// up
	{
		matrix->posy -= 20;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 125)// down
	{
		matrix->posy += 20;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 123)// left
	{
		matrix->posx -= 20;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 124)// right
	{
		matrix->posx += 20;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 116)//pgup
	{
		matrix->distance += 150;
		matrix->img = mk_image(*matrix);
		close(matrix->fd);
		matrix->fd = open(matrix->av, O_RDONLY);
		fdf(*matrix);
	}
	if (keycode == 121)//pgdown
	{
		if (matrix->distance >= 151)
		{
			matrix->distance -= 150;
			matrix->img = mk_image(*matrix);
			close(matrix->fd);
			matrix->fd = open(matrix->av, O_RDONLY);
			fdf(*matrix);
		}
	}
	return (0);
}
