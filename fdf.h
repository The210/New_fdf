/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:53:12 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/26 21:23:53 by dhorvill         ###   ########.fr       */
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
	float		x;
	float		y;
	float		z;
}				t_coord;

typedef struct s_matrix
{
	float		Matx1;
	float		Matx2;
	float		Matx3;
	float		Maty1;
	float		Maty2;
	float		Maty3;
	float		Matz1;
	float		Matz2;
	float		Matz3;
	float		TMatx1;
	float		TMatx2;
	float		TMatx3;
	float		TMaty1;
	float		TMaty2;
	float		TMaty3;
	float		TMatz1;
	float		TMatz2;
	float		TMatz3;
	float		PMatx1;
	float		PMatx2;
	float		PMatx3;
	float		PMaty1;
	float		PMaty2;
	float		PMaty3;
	float		PMatz1;
	float		PMatz2;
	float		PMatz3;
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
}				t_matrix;

typedef struct s_mlx
{
}				t_mlx;

int		ft_draw_line2(int x0, int y0, int x1, int y1, int *img_string, int startz, int endz, int maxz);
int		interactive(int keycode, t_matrix *matrix);
int		fdf(t_matrix matrix);
char	**get_map(int fd);
#endif
