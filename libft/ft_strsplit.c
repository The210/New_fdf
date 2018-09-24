/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:36:51 by dhorvill          #+#    #+#             */
/*   Updated: 2018/06/08 22:43:12 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		len(char *s, size_t j, char c)
{
	size_t	l;
	int		k;

	k = j;
	l = 0;
	while (s[k] && s[k] != c)
	{
		l++;
		k++;
	}
	return (l);
}

static size_t		wcount(char *s, char c)
{
	int		i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			w++;
		i++;
	}
	return (w);
}

static char			**ssm(char **ss, int *t, char *x, char c)
{
	while (x[t[1]])
	{
		while (x[t[1]] == c && x[t[1]])
			t[1]++;
		if (x[t[1]] != '\0')
		{
			t[2] = 0;
			if ((ss[t[0]] = malloc(sizeof(char) * (len(x, t[1], c) + 1)))
					== NULL)
				return (NULL);
			while (x[t[1]] != c && x[t[1]])
				ss[t[0]][t[2]++] = x[t[1]++];
			ss[t[0]++][t[2]] = '\0';
		}
	}
	return (ss);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**ss;
	char	*x;
	int		t[3];

	t[0] = 0;
	t[1] = 0;
	ss = NULL;
	if (!s)
		return (NULL);
	if ((x = ft_strtrimc((char*)s, c)) == NULL)
		return (NULL);
	if ((ss = malloc(sizeof(ss) * wcount(x, c) + 1)) == NULL)
		return (NULL);
	ss = ssm(ss, t, x, c);
	ss[t[0]] = NULL;
	ft_strdel(&x);
	return (ss);
}
