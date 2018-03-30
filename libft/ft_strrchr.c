/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:15:19 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/09 17:24:42 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	while (s1[i])
		i++;
	while (i >= 0)
	{
		if (s1[i] == c)
			return (&s1[i]);
		i--;
	}
	if (!s1[i] && c == '\0')
		return (&s1[i]);
	return (NULL);
}
