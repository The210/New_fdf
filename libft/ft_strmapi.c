/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:25:07 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/14 14:07:24 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	int		i;

	i = 0;
	s2 = NULL;
	if (s && f)
	{
		while (s[i])
			i++;
		if ((s2 = (char *)malloc(sizeof(char) * (i + 1))) == 0)
			return (NULL);
		i = 0;
		while (s[i])
		{
			s2[i] = f(i, s[i]);
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
