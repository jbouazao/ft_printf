/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:14:16 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/22 18:35:15 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int				temp;
	int				counter;
	unsigned int	nb;

	counter = 1;
	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	temp = nb;
	while ((temp = temp / 10) != 0)
		counter *= 10;
	while (counter)
	{
		ft_putchar((nb / counter) + '0');
		nb = nb % counter;
		counter /= 10;
	}
}
