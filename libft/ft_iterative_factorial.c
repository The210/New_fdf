/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:24:38 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/12 15:30:36 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int counter;

	counter = nb;
	if (counter > 12 || counter < 0)
		return (0);
	else if (counter == 0)
		return (1);
	else
	{
		while (nb > 1)
		{
			counter = counter * (nb - 1);
			nb--;
		}
		return (counter);
	}
}
