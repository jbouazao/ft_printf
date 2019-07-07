/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:47:32 by oelbelam          #+#    #+#             */
/*   Updated: 2019/07/07 22:37:54 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_pow(int nbr,int power)
{
	if (power == 0)
		return (1);
	while (--power != 0)
		nbr *= nbr;
	return (nbr);
}

unsigned long long		ft_nbr_oct(unsigned long long	nbr)
{
	unsigned long long	res;
	unsigned long long	mod;
	unsigned long long 	div;
	int i;

	div = 1;
	i = 0;
	res = 0;
	while (nbr != 0)
	{
		res[index] = nbr % base;
		mod = nbr % 8;
		nbr = nbr / 8;
		res += ft_pow(10,i) * mod;
		i++;
	}
	return (res);
}
