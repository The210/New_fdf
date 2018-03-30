/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:40:41 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/10 18:04:42 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*a;
	size_t				i;

	i = 0;
	a = (unsigned char*)dst;
	while (i < n)
	{
		a[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dst);
}
