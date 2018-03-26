/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbisprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:40:16 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/13 17:27:48 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_afficheprime(int *j)
{
	int i;

	i = 0;
	while (j[i] != '\0')
	{
		ft_putnbr(j[i]);
		ft_putchar('\n');
		i++;
	}
}

int			*ft_nbprime(int nb)
{
	int i;
	int k;
	int *j;

	i = -1;
	k = 0;
	while (++i <= nb)
	{
		if (ft_is_prime(i) == 1)
			k++;
	}
	if ((j = (int*)malloc(sizeof(int) * (k + 1))) == 0)
		return (NULL);
	i = -1;
	k = 0;
	while (++i <= nb)
	{
		if (ft_is_prime(i) == 1)
			j[k++] = i;
	}
	j[k] = '\0';
	ft_afficheprime(j);
	ft_putnbr(k);
	ft_putchar('\n');
	return (j);
}
