/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:05 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/30 17:04:33 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	matrix_math(t_matrix matrix)
{
	matrix.Matx1 = (matrix.PMatx1 * matrix.TMatx1) +
		(matrix.PMatx2 * matrix.TMaty1) + (matrix.PMatx3 * matrix.TMatz1);
	matrix.Maty1 = (matrix.PMaty1 * matrix.TMatx1) +
		(matrix.PMaty2 * matrix.TMaty1) + (matrix.PMaty3 * matrix.TMatz1);
	matrix.Matx2 = (matrix.PMatx1 * matrix.TMatx2) +
		(matrix.PMatx2 * matrix.TMaty2) + (matrix.PMatx3 * matrix.TMatz2);
	matrix.Maty2 = (matrix.PMaty1 * matrix.TMatx2) +
		(matrix.PMaty2 * matrix.TMaty2) + (matrix.PMaty3 * matrix.TMatz2);
	matrix.Matx3 = (matrix.PMatx1 * matrix.TMatx3) +
		(matrix.PMatx2 * matrix.TMaty3) + (matrix.PMatx3 * matrix.TMatz3);
	matrix.Maty3 = (matrix.PMaty1 * matrix.TMatx3) +
		(matrix.PMaty2 * matrix.TMaty3) + (matrix.PMaty3 * matrix.TMatz3);
	return (matrix);
}

void		rotatex(int keycode, t_matrix *matrix)
{
	if (keycode == 91)
	{
		matrix->TMatx1 = 1;
		matrix->TMatx2 = 0;
		matrix->TMatx3 = 0;
		matrix->TMaty1 = 0;
		matrix->TMatz1 = 0;
		matrix->TMaty2 = cos(matrix->thetax);
		matrix->TMaty3 = -sin(matrix->thetax);
		matrix->TMatz2 = sin(matrix->thetax);
		matrix->TMatz3 = cos(matrix->thetax);
	}
	if (keycode == 84)
	{
		matrix->TMatx1 = 1;
		matrix->TMatx2 = 0;
		matrix->TMatx3 = 0;
		matrix->TMaty1 = 0;
		matrix->TMatz1 = 0;
		matrix->TMaty2 = cos(matrix->thetax);
		matrix->TMaty3 = sin(matrix->thetax);
		matrix->TMatz2 = -sin(matrix->thetax);
		matrix->TMatz3 = cos(matrix->thetax);
	}
}

void		rotatey(int keycode, t_matrix *matrix)
{
	if (keycode == 88)
	{
		matrix->TMaty2 = 1;
		matrix->TMaty1 = 0;
		matrix->TMaty3 = 0;
		matrix->TMatx2 = 0;
		matrix->TMatz2 = 0;
		matrix->TMatx1 = cos(matrix->thetay);
		matrix->TMatx3 = sin(matrix->thetay);
		matrix->TMatz1 = -sin(matrix->thetay);
		matrix->TMatz3 = cos(matrix->thetay);
	}
	if (keycode == 86)
	{
		matrix->TMaty2 = 1;
		matrix->TMaty1 = 0;
		matrix->TMaty3 = 0;
		matrix->TMatx2 = 0;
		matrix->TMatz2 = 0;
		matrix->TMatx1 = cos(matrix->thetay);
		matrix->TMatx3 = -sin(matrix->thetay);
		matrix->TMatz1 = sin(matrix->thetay);
		matrix->TMatz3 = cos(matrix->thetay);
	}
}

void		rotatez(int keycode, t_matrix *matrix)
{
	if (keycode == 92)
	{
		matrix->TMatz3 = 1;
		matrix->TMatz2 = 0;
		matrix->TMatz1 = 0;
		matrix->TMatx3 = 0;
		matrix->TMaty3 = 0;
		matrix->TMatx1 = cos(matrix->thetaz);
		matrix->TMaty1 = sin(matrix->thetaz);
		matrix->TMatx2 = -sin(matrix->thetaz);
		matrix->TMaty2 = cos(matrix->thetaz);
	}
	if (keycode == 89)
	{
		matrix->TMatz3 = 1;
		matrix->TMatz2 = 0;
		matrix->TMatz1 = 0;
		matrix->TMatx3 = 0;
		matrix->TMaty3 = 0;
		matrix->TMatx1 = cos(matrix->thetaz);
		matrix->TMaty1 = -sin(matrix->thetaz);
		matrix->TMatx2 = sin(matrix->thetaz);
		matrix->TMaty2 = cos(matrix->thetaz);
	}
}

void		rotation(int keycode, t_matrix *matrix)
{
	*matrix = init_temps(*matrix);
	rotatex(keycode, matrix);
	rotatey(keycode, matrix);
	rotatez(keycode, matrix);
	if (keycode == 89 || keycode == 92 || keycode == 86
	|| keycode == 88 || keycode == 84 || keycode == 91)
		*matrix = matrix_math(*matrix);
}
