/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:51:57 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/11 12:36:46 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		puis(int no, int i)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (y <= i)
	{
		x *= no;
		y++;
	}
	return (x);
}

void			ft_putnbr_fd(int nb, int fd)
{
	int	count;
	int n;

	count = 1;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = (nb * -1) - 2000000000;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	n = nb;
	while (n >= 1)
	{
		n = n / 10;
		count++;
	}
	while (--count > 0)
		ft_putchar_fd((nb / puis(10, (count - 1))) % 10 + '0', fd);
}
