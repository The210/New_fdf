/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:36:24 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/13 18:30:06 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	while (needle[i])
		i++;
	if (i < 1)
		return ((char *)haystack);
	else
	{
		i = 0;
		while (haystack[i])
		{
			j = 0;
			while (needle[j] == haystack[i + j])
			{
				if (needle[j + 1] == '\0')
					return ((char *)(haystack + i));
				j++;
			}
			i++;
		}
		return (0);
	}
}
