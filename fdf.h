/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:53:12 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/30 18:07:28 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include "get_next_line.h"
# include <math.h>

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
}				t_coord;

typedef struct	s_matrix
{
	int			kx;
	int			ky;
	float		matx1;
	float		matx2;
	float		matx3;
	float		maty1;
	float		maty2;
	float		maty3;
	float		matz1;
	float		matz2;
	float		matz3;
	float		tmatx1;
	float		tmatx2;
	float		tmatx3;
	float		tmaty1;
	float		tmaty2;
	float		tmaty3;
	float		tmatz1;
	float		tmatz2;
	float		tmatz3;
	float		pmatx1;
	float		pmatx2;
	float		pmatx3;
	float		pmaty1;
	float		pmaty2;
	float		pmaty3;
	float		pmatz1;
	float		pmatz2;
	float		pmatz3;
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_string;
	int			bpp;
	int			s_l;
	int			endian;
	int			fd;
	int			lines;
	float		thetax;
	float		thetay;
	float		thetaz;
	char		*av;
	float		a;
	float		b;
	float		c;
	float		alt;
	float		v;
	int			posx;
	int			posy;
	int			col;
	char		**map;
	int			flag;
	int			distance;
	int			num_num;
	int			*num_col;
	int			counted;
	int			color;
	float		dx;
	int			sx;
	float		dy;
	int			sy;
	float		m;
	float		pb;
	int			intm;
	int			intb;
}				t_matrix;

int				ft_draw_line2(t_coord point,
				t_coord next_point, t_matrix matrix);
int				interactive(int keycode, t_matrix *matrix);
int				fdf(t_matrix matrix);
char			**get_map(int fd);
void			draw_across(t_matrix matrix, t_coord point, t_coord next_point);
void			draw_columns(t_matrix matrix,
				t_coord point, t_coord next_point);
int				num_len(char *map, char c);
t_matrix		get_lines(char *argv, t_matrix matrix);
t_matrix		init_matrix(t_matrix *matrix);
void			rotation(int keycode, t_matrix *matrix);
t_matrix		init_temps(t_matrix matrix);
#endif
