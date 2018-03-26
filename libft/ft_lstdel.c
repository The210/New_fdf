/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:59:03 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/13 17:02:11 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	while (alst && *alst)
	{
		temp = *alst;
		(*del)((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(temp);
	}
	*alst = NULL;
}
