/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:32:14 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/13 22:32:42 by dhorvill         ###   ########.fr       */
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

void			ft_putnbrl(int nb)
{
	int	count;
	int n;

	count = 1;
	if (nb == 0)
		ft_putchar('0');
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = (nb * -1) - 2000000000;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	n = nb;
	while (n >= 1)
	{
		n = n / 10;
		count++;
	}
	while (--count > 0)
		ft_putchar((nb / puis(10, (count - 1))) % 10 + '0');
	ft_putchar('\n');
}
