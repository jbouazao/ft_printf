/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:40:21 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/22 18:50:25 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				temp;
	int				counter;
	unsigned int	nb;

	counter = 1;
	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	temp = nb;
	while ((temp = temp / 10) != 0)
		counter *= 10;
	while (counter)
	{
		ft_putchar_fd(((nb / counter) + '0'), fd);
		nb = nb % counter;
		counter /= 10;
	}
}
