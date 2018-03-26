/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:15:49 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/11 12:47:04 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = "";
	if ((str = (char *)malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	while ((int)size)
	{
		str[size] = '\0';
		size--;
	}
	str[size] = '\0';
	return (str);
}
