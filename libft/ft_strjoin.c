/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:57:41 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/14 14:25:10 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = -1;
	s3 = "";
	if (s1 && s2)
	{
		s3 = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
		if (s3 == NULL)
			return (NULL);
		while (s1[++i])
			s3[i] = s1[i];
		while (s2[++j])
		{
			s3[i] = s2[j];
			i++;
		}
		s3[i] = '\0';
	}
	return (s3);
}
