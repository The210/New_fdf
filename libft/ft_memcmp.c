/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:10:13 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/11 14:23:05 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			o;

	i = 0;
	o = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ss1[i] == ss2[i] && i < n - 1)
		i++;
	if (i == n)
		o = ss1[i - 1] - ss2[i - 1];
	else
		o = ss1[i] - ss2[i];
	return (o);
}
