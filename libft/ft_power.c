/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:13:33 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/12 15:14:07 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_power(float a, int n)
{
	int		i;
	float	b;
	int		j;

	i = 1;
	b = a;
	if (n < 0)
		j = -n;
	else
		j = n;
	if (n == 0)
		return (1);
	while (i < j)
	{
		a = a * b;
		i++;
	}
	if (n < 0)
		return (1 / a);
	else
		return (a);
}
