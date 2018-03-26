/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:58:01 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/14 14:09:42 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = "";
	i = -1;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		str = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
		if (str == NULL)
			return (NULL);
		while (s1[++i])
			str[i] = s1[i];
		while (s2[j])
		{
			str[i] = s2[j];
			j++;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
