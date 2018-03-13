/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 18:09:30 by smerelo           #+#    #+#             */
/*   Updated: 2018/03/06 22:58:07 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			get_lines(int fd, char *argv)
{
	int i;
	char *map;

	i = 0;
	while (get_next_line(fd, &map) > 0)
	{
		ft_strdel(&map);
		i++;
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	return (i);
}

float			get_nbr(char *map_row, int index)
{
	float j;
	int	i;

	j = 0;
	while (map_row[index] && map_row[index] != ' ' && index > 0)
		index--;
	while (map_row[index] && map_row[index] == ' ')
		index++;
	while(map_row[index] && map_row[index] != ' ')
	{
		j = j * 10 + map_row[index] - '0';
		index++;
	}
	return (-j);
}

int			next_index(char *map, int index)
{

	while(map[index] && map[index] != ' ')
		index++;
	while(map[index] && map[index] == ' ')
		index++;
	return (index);
}

t_coord		map_2d(float x, float y, float z, t_coord point, t_matrix matrix)
{
	int sz;
	int f;
	float tempx;
	float tempy;

	tempy = y;
	tempx = x;
	f = 0;
//	if (x == 0 && y == 100)
//	{
//		f = 1;
	//	printf(" X1: %f\n Y1: %f\n Z1: %f\n", x, y, z);
//	}	
	x = (matrix.Matx1 * tempx + matrix.Matx2 * tempy + matrix.Matx3 * z) * 500;
	y = (matrix.Maty1 * tempx+ matrix.Maty2 * tempy + matrix.Maty3 * z) * 500;
	z = (matrix.Matz1 * tempx + matrix.Matz2 * tempy + matrix.Matz3 * z); 
//	if (f == 1)
//	{
	//	printf(" X: %f\n Y: %f\n Z: %f\n Maty2: %f\n Maty3: %f\n Matz2 %f\n Matz3 %f\n thetax: %f\n", x, y, z, matrix.Maty2, matrix.Maty3, matrix.Matz2, matrix.Matz3, matrix.thetax);
//	}
	sz = 1;
	if (z == 0)
		z += 1;
	point.y = 700 + (y + 1) / (z * 10);
	point.x = 1000 +( x + 1) / (z * 10);
//	if (f == 1)
//	{
//		printf(" point.x: %f\n point.y: %f\n", point.x, point.y);
//	}
	return (point);
}

int		fdf(t_matrix matrix)
{
	char 	*map;
	int		x;
	int		index;
	char	**map2;
	int		indey;
	int debug;
	t_coord	point;
	t_coord next_point;
	indey = 0;
	while (get_next_line(matrix.fd, &map) > 0)
	{
		index = 0;
		x = 0;
		while (map[index + 4])
		{
			if (!next_index(map, indey))
				break ;
			point = map_2d(x + matrix.a, indey + matrix.b, (get_nbr(map, index))/ 10 * matrix.alt+ 2 + matrix.c, point, matrix);
			next_point = map_2d(x + 1 + matrix.a, indey + matrix.b, (get_nbr(map, next_index(map, index)))/ 10 * matrix.alt + 2 + matrix.c, next_point, matrix);
			ft_draw_line2(point.x + matrix.posx, point.y + matrix.posy, next_point.x + matrix.posx, next_point.y + matrix.posy, matrix.img_string);
			index = next_index(map, index);
			x++;
		}
		ft_strdel(&map);
		indey++;
	}
	close(matrix.fd);
	matrix.fd = open(matrix.av, O_RDONLY);
	if ((map2 = (char**)malloc(sizeof(map2) * (matrix.lines + 100))) == NULL)
		return(0);
	map2[matrix.lines] = NULL;
	indey = 0;
	while (get_next_line(matrix.fd, &map2[indey]) > 0)
		indey++;
	x = 0;
	debug = 0;
	index = 0;
	while(x < ft_strlen(map2[0]) - 1)
	{
		//usleep(5000);
		//ft_putstr("######LOOPX######");
	//	ft_putnbrl(x);
		indey = 0;
		while (indey < matrix.lines -1)
		{
		//ft_putstr("#####LOOPY#####");
		//ft_putnbrl(indey);
			point = map_2d(index + matrix.a, indey+ matrix.b, (get_nbr(map2[indey], x)) * matrix.alt/ 10 + 2 + matrix.c, point, matrix);
			next_point = map_2d(index + matrix.a, (indey + 1) + matrix.b, (get_nbr(map2[indey + 1], x))/ 10 *matrix.alt + matrix.c+ 2, point, matrix);
			ft_draw_line2(point.x + matrix.posx, point.y + matrix.posy, next_point.x + matrix.posx, next_point.y + matrix.posy, matrix.img_string);
		/*	ft_putstr("x1: ");
			ft_putnbrl(point.x);
			ft_putstr("y1: ");
			ft_putnbrl(point.y);
			ft_putstr("x2: ");
			ft_putnbrl(next_point.x);
			ft_putstr("y2: ");
			ft_putnbrl(next_point.y);
			ft_putstr("z1: ");
			ft_putnbrl(get_nbr(map2[indey], x));
			ft_putstr("z2: ");
			ft_putnbrl(get_nbr(map2[indey], next_index(map2[indey], x)));
			ft_putstr("X: ");
			ft_putnbrl(x);*/
			indey++;
		}
		/*while(map2[debug])
		{
			ft_putendl(map2[debug]);
			debug++;
		}*/
		x = next_index(map2[0], x);
		index++;
	}
	mlx_put_image_to_window(matrix.mlx, matrix.win, matrix.img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	char *str;
	t_matrix	matrix;
	
	matrix.posx = -0;
	matrix.posy = -0;
	matrix.a = 0;
	matrix.b = 0;
	matrix.c = 0;
	matrix.v = 1;
	matrix.alt = 0.5;
	matrix.thetax = 0.01;
	matrix.thetay = 0.01;
	matrix.thetaz = 0.01;
	matrix.Matx1 = cos(matrix.thetaz);
	matrix.Matx2 = -sin(matrix.thetaz);
	matrix.Matx3 = 0;
	matrix.Maty1 = sin(matrix.thetaz);
	matrix.Maty2 = cos(matrix.thetaz);;
	matrix.Maty3 = 0;
	matrix.Matz1 = 0;
	matrix.Matz2 = 0;
	matrix.Matz3 = 1;
	matrix.TMatx1 = 0;
	matrix.TMatx2 = 0;
	matrix.TMatx3 = 0;
	matrix.TMaty1 = 0;
	matrix.TMaty2 = 0;
	matrix.TMaty3 = 0;
	matrix.TMatz1 = 0;
	matrix.TMatz2 = 0;
	matrix.TMatz3 = 0;
	matrix.av = av[1];
	matrix.fd = open(av[1], O_RDONLY);
	matrix.mlx = mlx_init();
	matrix.win = mlx_new_window(matrix.mlx, 2000, 1400, "TrueFDF");
	matrix.img = mlx_new_image(matrix.mlx, 2000, 2000);
	matrix.img_string = (int*)mlx_get_data_addr(matrix.img, &(matrix.bpp), &(matrix.s_l), &(matrix.endian));
	matrix.lines = get_lines(matrix.fd, av[1]); 
	fdf(matrix);
	mlx_key_hook(matrix.win, interactive, (void *)&matrix);
	mlx_loop(matrix.mlx);
	return (0);
}
