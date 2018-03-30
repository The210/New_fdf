/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:50:43 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/13 20:46:15 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss1;

	i = 0;
	ss1 = (unsigned char *)s;
	while (i < n)
	{
		if (ss1[i] == (unsigned char)c)
			return (&ss1[i]);
		i++;
	}
	return (NULL);
}
