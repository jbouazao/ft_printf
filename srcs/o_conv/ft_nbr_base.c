/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:47:32 by oelbelam          #+#    #+#             */
/*   Updated: 2019/07/08 11:52:38 by oelbelam         ###   ########.fr       */
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

char	*ft_nbr_oct(unsigned long long	nbr)
{
	unsigned long long	temp;
	int					count;
	char				*str;
	
	temp = nbr;
	count = 0;
	if (nbr == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (temp != 0)
	{
		temp = temp / 8;
		count++;
	}
	str = ft_strnew(count);
	str[count--] = '\0';
	while (nbr != 0)
	{
		str[count] = nbr % 8 + '0';
		nbr /= 8;
		count--;
	}
	return (str);
}
