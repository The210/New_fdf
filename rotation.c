/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:05 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/30 18:11:38 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	matrix_math(t_matrix matrix)
{
	matrix.matx1 = (matrix.pmatx1 * matrix.tmatx1) +
		(matrix.pmatx2 * matrix.tmaty1) + (matrix.pmatx3 * matrix.tmatz1);
	matrix.maty1 = (matrix.pmaty1 * matrix.tmatx1) +
		(matrix.pmaty2 * matrix.tmaty1) + (matrix.pmaty3 * matrix.tmatz1);
	matrix.matx2 = (matrix.pmatx1 * matrix.tmatx2) +
		(matrix.pmatx2 * matrix.tmaty2) + (matrix.pmatx3 * matrix.tmatz2);
	matrix.maty2 = (matrix.pmaty1 * matrix.tmatx2) +
		(matrix.pmaty2 * matrix.tmaty2) + (matrix.pmaty3 * matrix.tmatz2);
	matrix.matx3 = (matrix.pmatx1 * matrix.tmatx3) +
		(matrix.pmatx2 * matrix.tmaty3) + (matrix.pmatx3 * matrix.tmatz3);
	matrix.maty3 = (matrix.pmaty1 * matrix.tmatx3) +
		(matrix.pmaty2 * matrix.tmaty3) + (matrix.pmaty3 * matrix.tmatz3);
	return (matrix);
}

void		rotatex(int keycode, t_matrix *matrix)
{
	if (keycode == 91)
	{
		matrix->tmatx1 = 1;
		matrix->tmatx2 = 0;
		matrix->tmatx3 = 0;
		matrix->tmaty1 = 0;
		matrix->tmatz1 = 0;
		matrix->tmaty2 = cos(matrix->thetax);
		matrix->tmaty3 = -sin(matrix->thetax);
		matrix->tmatz2 = sin(matrix->thetax);
		matrix->tmatz3 = cos(matrix->thetax);
	}
	if (keycode == 84)
	{
		matrix->tmatx1 = 1;
		matrix->tmatx2 = 0;
		matrix->tmatx3 = 0;
		matrix->tmaty1 = 0;
		matrix->tmatz1 = 0;
		matrix->tmaty2 = cos(matrix->thetax);
		matrix->tmaty3 = sin(matrix->thetax);
		matrix->tmatz2 = -sin(matrix->thetax);
		matrix->tmatz3 = cos(matrix->thetax);
	}
}

void		rotatey(int keycode, t_matrix *matrix)
{
	if (keycode == 88)
	{
		matrix->tmaty2 = 1;
		matrix->tmaty1 = 0;
		matrix->tmaty3 = 0;
		matrix->tmatx2 = 0;
		matrix->tmatz2 = 0;
		matrix->tmatx1 = cos(matrix->thetay);
		matrix->tmatx3 = sin(matrix->thetay);
		matrix->tmatz1 = -sin(matrix->thetay);
		matrix->tmatz3 = cos(matrix->thetay);
	}
	if (keycode == 86)
	{
		matrix->tmaty2 = 1;
		matrix->tmaty1 = 0;
		matrix->tmaty3 = 0;
		matrix->tmatx2 = 0;
		matrix->tmatz2 = 0;
		matrix->tmatx1 = cos(matrix->thetay);
		matrix->tmatx3 = -sin(matrix->thetay);
		matrix->tmatz1 = sin(matrix->thetay);
		matrix->tmatz3 = cos(matrix->thetay);
	}
}

void		rotatez(int keycode, t_matrix *matrix)
{
	if (keycode == 92)
	{
		matrix->tmatz3 = 1;
		matrix->tmatz2 = 0;
		matrix->tmatz1 = 0;
		matrix->tmatx3 = 0;
		matrix->tmaty3 = 0;
		matrix->tmatx1 = cos(matrix->thetaz);
		matrix->tmaty1 = sin(matrix->thetaz);
		matrix->tmatx2 = -sin(matrix->thetaz);
		matrix->tmaty2 = cos(matrix->thetaz);
	}
	if (keycode == 89)
	{
		matrix->tmatz3 = 1;
		matrix->tmatz2 = 0;
		matrix->tmatz1 = 0;
		matrix->tmatx3 = 0;
		matrix->tmaty3 = 0;
		matrix->tmatx1 = cos(matrix->thetaz);
		matrix->tmaty1 = -sin(matrix->thetaz);
		matrix->tmatx2 = sin(matrix->thetaz);
		matrix->tmaty2 = cos(matrix->thetaz);
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
