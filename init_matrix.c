/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:36:04 by dhorvill          #+#    #+#             */
/*   Updated: 2018/06/05 17:36:05 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	init_temps(t_matrix matrix)
{
	matrix.pmatx1 = matrix.matx1;
	matrix.pmatx2 = matrix.matx2;
	matrix.pmatx3 = matrix.matx3;
	matrix.pmaty1 = matrix.maty1;
	matrix.pmaty2 = matrix.maty2;
	matrix.pmaty3 = matrix.maty3;
	matrix.pmatz1 = matrix.matz1;
	matrix.pmatz2 = matrix.matz2;
	matrix.pmatz3 = matrix.matz3;
	return (matrix);
}

t_matrix	init_matrix2(t_matrix *matrix)
{
	matrix->tmatx1 = 0;
	matrix->tmatx2 = 0;
	matrix->tmatx3 = 0;
	matrix->tmaty1 = 0;
	matrix->tmaty2 = 0;
	matrix->tmaty3 = 0;
	matrix->tmatz1 = 0;
	matrix->tmatz2 = 0;
	matrix->distance = 1000;
	matrix->tmatz3 = 0;
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
	matrix->matx1 = 0.731533;
	matrix->matx2 = -0.674732;
	matrix->matx3 = 0.097951;
	matrix->maty1 = 0.585779;
	matrix->maty2 = 0.548469;
	matrix->maty3 = -0.596695;
	matrix->matz1 = 0;
	matrix->matz2 = 0;
	matrix->matz3 = 0;
	init_matrix2(matrix);
	return (*matrix);
}
