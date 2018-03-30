/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:27:00 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/09 17:27:03 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
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
