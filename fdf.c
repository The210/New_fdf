/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:36:18 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/26 23:23:10 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int num_len(char *map, char c)
{
	int i;
	int sym;
	int count;

	i = 0;
	sym = 0;
	count = 0;
	while(map[i])
	{
		while (map[i] && map[i] != c)
		{
			sym = 1;
			i++;
		}
		while (map[i] && map[i] == c)
		{
			count += sym;
			sym = 0;
			i++;
		}
	}
	return (count + 1);
}

/*t_matrix	get_lines(char *argv, t_matrix matrix)
{
	int i;
	int curr_length;
	int prev_length;
	char *map;

	i = 0;
	prev_length = 0;
	while (get_next_line(matrix.fd, &map) > 0)
	{
		curr_length = num_len(map, ' ');
		//matrix.col_line[i] = curr_length;
		if (prev_length != curr_length && i != 0)
		{
			matrix.flag = 1;
			ft_putendl("Error: invalid map");
			return (matrix);
		}
		prev_length = curr_length;
		ft_strdel(&map);
		i++;
	}
	close(matrix.fd);
	matrix.fd = open(argv, O_RDONLY);
	matrix.lines = i;
	matrix.col = curr_length;
	return (matrix);
}*/

t_matrix	get_lines(char *argv, t_matrix matrix)
{
	int i;
	int	length;
	char	*map;

	i = 0;
	matrix.num_num = 0;
	while (get_next_line(matrix.fd, &map) > 0)
	{
		length = num_len(map, ' ');
		ft_strdel(&map);
		i++;
	}
	close(matrix.fd);
	matrix.fd = open(argv, O_RDONLY);
	matrix.lines = i;
	if ((matrix.num_col = (int*)malloc(sizeof(int*) * (i + 1))) == 0)
	{
		matrix.flag = 1;
		return(matrix);
	}
	matrix.num_col[i] = '\0';
	i = 0;
	while (get_next_line(matrix.fd, &map) > 0)
	{
		length = num_len(map, ' ');
		ft_strdel(&map);
		matrix.num_col[i] = length;
		matrix.num_num += length;
		i++;
	}
	close(matrix.fd);
	matrix.fd = open(argv, O_RDONLY);
	matrix.col = length;
	return (matrix);
}

float				get_nbr(char *map)
{
	float j;
	int i;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = j * 10 + map[i] - '0';
		i++;
	}
	return (j);
}

t_coord		map_2d(float x, float y, float z, t_coord point, t_matrix matrix)
{
	float tempx;
	float tempy;

	tempy = y;
	tempx = x;
	point.x = (matrix.Matx1 * tempx + matrix.Matx2 * tempy + matrix.Matx3 * z) * (matrix.distance / (matrix.num_num / matrix.lines));
	point.y = (matrix.Maty1 * tempx+ matrix.Maty2 * tempy + matrix.Maty3 * z) * (matrix.distance / (matrix.num_num / matrix.lines));
	return (point);
}

/*void	draw_across(t_matrix matrix, t_coord point, t_coord next_point)
{
	int x;
	int y;

	x = 1;
	y = 0;
	while (matrix.map[x])
	{
		while(matrix.lines * matrix.col >= x && (x % matrix.col != 0 || x == 0))
		{
			point = map_2d((x - 1 - (y * matrix.col)) + matrix.a, y + matrix.b, (get_nbr(matrix.map[x - 1])) / 50 * matrix.alt + 2+ matrix.c, point, matrix);
			x++;
			next_point = map_2d((x - 1 - (y * matrix.col)) + matrix.a, y + matrix.b, (get_nbr(matrix.map[x - 1])) / 50 * matrix.alt +2 +matrix.c, point, matrix);
			ft_draw_line2(point.x + matrix.posx, point.y + matrix.posy, next_point.x + matrix.posx, next_point.y + matrix.posy, matrix.img_string, (get_nbr(matrix.map[x - 1])) / 50 * matrix.alt + 2 + matrix.c * -1, (get_nbr(matrix.map[x - 2])) / 50 * matrix.alt * -1, 1 * matrix.alt + 2 + matrix.c);
		}
		y++;
			x++;
	}
}*/

void	draw_across(t_matrixmatrix, t_coord point, t_coord next_point);

void	draw_columns(t_matrix matrix, t_coord point, t_coord next_point)
{
	int	x;
	int	y;
	int indey;

	x = 0;
	while(x < matrix.col)
	{
		indey = x;
		y = 0;
		while (y < matrix.lines - 1)
		{
			point = map_2d(x + matrix.a, y + matrix.b, (get_nbr(matrix.map[indey])) * matrix.alt/ 50 + 2 + matrix.c, point, matrix);
			next_point = map_2d(x + matrix.a, y + 1 + matrix.b, (get_nbr(matrix.map[indey + matrix.col]))/ 50 *matrix.alt + matrix.c+ 2, point, matrix);
			ft_draw_line2(point.x + matrix.posx, point.y + matrix.posy, next_point.x + matrix.posx, next_point.y + matrix.posy, matrix.img_string, (get_nbr(matrix.map[indey])) * matrix.alt/ 50 + 2 + matrix.c * -1,(get_nbr(matrix.map[indey + matrix.col]))/ 50 *matrix.alt + matrix.c+ 2 * -1, 1 * matrix.alt + matrix.c + 2);
			indey += matrix.col;
			y++;
		}
		x++;
	}
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
	draw_across(matrix, point, next_point);
	draw_columns(matrix, point, next_point);
	mlx_put_image_to_window(matrix.mlx, matrix.win, matrix.img, 0, 0);
	return (0);
}

t_matrix	init_matrix(t_matrix matrix)
{
	matrix.posx = 600;
	matrix.posy = 500;
	matrix.a = 0;
	matrix.b = 0;
	matrix.c = 0;
	matrix.v = 1;
	matrix.alt = 50;
	matrix.thetax = 0.11;
	matrix.thetay = 0.11;
	matrix.thetaz = 0.11;
	matrix.Matx1 = cos(matrix.thetaz);
	matrix.Matx2 = -sin(matrix.thetaz);
	matrix.Matx3 = 0;
	matrix.Maty1 = sin(matrix.thetaz);
	matrix.Maty2 = cos(matrix.thetaz);
	matrix.Maty3 = 0;
	matrix.Matz1 = 0;
	matrix.Matz2 = 0;
	matrix.Matz3 = 1;
	matrix.TMatx1 = 0;
	matrix.TMatx2 = 0;
	matrix.TMatx3 = 0;
	matrix.TMaty1 = 0;
	matrix.TMaty2 = 0;
	return (matrix);
}

int		main(int ac, char **av)
{
	char *str;
	t_matrix	matrix;

	matrix = init_matrix(matrix);
	matrix.TMaty3 = 0;
	matrix.TMatz1 = 0;
	matrix.TMatz2 = 0;
	matrix.distance = 1000;
	matrix.TMatz3 = 0;
	matrix.av = av[1];
	if ((matrix.fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putendl("Error: Read failed");
		return (0);
	}
	matrix.mlx = mlx_init();
	matrix.win = mlx_new_window(matrix.mlx, 2000, 1400, "TrueFDF");
	matrix.img = mlx_new_image(matrix.mlx, 2000, 2000);
	matrix.img_string = (int*)mlx_get_data_addr(matrix.img, &(matrix.bpp), &(matrix.s_l), &(matrix.endian));
	matrix = get_lines(av[1], matrix);
	matrix.map = get_map(matrix.fd);
	close(matrix.fd);
	matrix.fd = open(av[1], O_RDONLY);
	if (matrix.flag == 1)
		return (0);
	ft_putnbrl(matrix.col);
	ft_putnbrl(matrix.lines);
	ft_putnbrl(matrix.col * matrix.lines);
//	matrix.col = (ft_tablen(matrix.map) / matrix.lines);
	fdf(matrix);
	mlx_key_hook(matrix.win, interactive, (void *)&matrix);
	mlx_loop(matrix.mlx);
	return (0);
}
