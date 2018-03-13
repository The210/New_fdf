/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 01:39:46 by smerelo           #+#    #+#             */
/*   Updated: 2018/03/06 20:51:08 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int		ft_draw_line2(int x0, int y0, int x1, int y1, int *img_string)
{
	float dx;
	int sx;
	float dy;
	int sy;
	float m;
	float b;
	int intm;
	int intb;

	if (x0 == x1 && y0 == y1)
	{
		if (x0 < 2000 && y0 < 1399 && x0 >= 0 && y0 >= 0) 
			img_string[y0 * 2000 + x0] = 0xFFFFFF;
		return (0);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	sx = (dx < 0) ? -1 : 1;
	sy = (dy < 0) ? -1 : 1;

	if (fabsf(dy) < fabsf(dx))
	{
		m = dy / dx;
		b = y0 - m * x0;
		while (x0 != x1)
		{
			intm = round(m * x0 + b);
			if (x0 < 2000 && y0 < 1399 && x0 >= 0 && y0 >= 0) 
				img_string[intm * 2000 + x0] = 0xFFFFFF;
			x0 += sx;
		}
	}
	else
	{
		m = dx / dy;
		b = x0 - m * y0;
		while (y0 != y1)
		{
			intb = round(m * y0 + b);
			if (x0 < 2000 && y0 < 1399 && x0 >= 0 && y0 >= 0) 
				img_string[y0 * 2000 + intb] = 0xFFFFFF;
			y0 += sy;
		}
	}
	if (x0 < 2000 && y0 < 1399 && x0 >= 0 && y0 >= 0) 
		img_string[y1 * 2000 + x1] = 0xFFFFFF;
	return (0);
}

/*int		not_main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		bpp;
	int		s_l;
	int		endian;
	int	*img_string;
	int		i;
	int		n;
	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "FdF");
	img = mlx_new_image(mlx_ptr, 800, 600);
	img_string = (int *)mlx_get_data_addr(img, &(bpp), &(s_l), &(endian));
	ft_draw_line2(0, 0, 255, 345, img_string, mlx_ptr, win_ptr); 
	*while(i <= 600)
	  {
	  n = -1;
	  while(++n <= 800)
	  {
	  if(n)
	  img_string[i * 800 + n] = 0xFFFFFF;
	  else
	  img_string[i * 800 + n] = 0xFFFFFF;
	  }
	  i++;
	  /

	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}*/
