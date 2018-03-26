/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:42:44 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/13 21:06:05 by dhorvill         ###   ########.fr       */
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
