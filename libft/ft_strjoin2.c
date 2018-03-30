/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 05:29:39 by smerelo           #+#    #+#             */
/*   Updated: 2018/03/30 16:50:48 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*ss;

	if (!s1 || !s2)
		return (NULL);
	if ((ss = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2)) == NULL)
		return (NULL);
	ft_strcpy(ss, (char*)s1);
	ft_strcat(ss, s2);
	ss[ft_strlen(s1) + ft_strlen(s2)] = ' ';
	ss[ft_strlen(s1) + ft_strlen(s2) + 2] = '\0';
	return (ss);
}
