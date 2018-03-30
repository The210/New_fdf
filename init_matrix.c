/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:08:41 by smerelo           #+#    #+#             */
/*   Updated: 2018/03/30 16:58:25 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_matrix	init_matrix2(t_matrix *matrix)
{
	matrix->TMatx1 = 0;
	matrix->TMatx2 = 0;
	matrix->TMatx3 = 0;
	matrix->TMaty1 = 0;
	matrix->TMaty2 = 0;
	matrix->TMaty3 = 0;
	matrix->TMatz1 = 0;
	matrix->TMatz2 = 0;
	matrix->distance = 1000;
	matrix->TMatz3 = 0;
	matrix->color = 0xffffff;
	return (*matrix);
}

t_matrix	init_matrix(t_matrix *matrix)
{
	matrix->posx = 1050;
	matrix->posy = 590;
	matrix->a = 0;
	matrix->b = 0;
	matrix->c = 0;
	matrix->v = 1;
	matrix->alt = 0.1;
	matrix->thetax = 0.11;
	matrix->thetay = 0.11;
	matrix->thetaz = 0.11;
	matrix->Matx1 = 0.731533;
	matrix->Matx2 = -0.674732;
	matrix->Matx3 = 0.097951;
	matrix->Maty1 = 0.585779;
	matrix->Maty2 = 0.548469;
	matrix->Maty3 = -0.596695;
	matrix->Matz1 = 0;
	matrix->Matz2 = 0;
	matrix->Matz3 = 0;
	init_matrix2(matrix);
	return (*matrix);
}
