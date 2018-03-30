/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:04:17 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/11 15:48:58 by ybouzgao         ###   ########.fr       */
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
