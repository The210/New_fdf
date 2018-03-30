/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:08:58 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/13 14:38:17 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && *alst)
	{
		while (*alst)
		{
			temp = *alst;
			(*del)((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(temp);
		}
	}
	*alst = NULL;
}
