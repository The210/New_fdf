/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:23:11 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/14 14:20:22 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ss;
	size_t		i;

	i = 0;
	if ((ss = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	if (s)
	{
		while (i < len)
		{
			ss[i] = s[start];
			i++;
			start++;
		}
		ss[i] = '\0';
	}
	return (ss);
}
