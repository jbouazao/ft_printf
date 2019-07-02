/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_solv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:21:27 by jbouazao          #+#    #+#             */
/*   Updated: 2019/07/02 16:11:10 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nbrlen(long long int nbr)
{
	if (nbr < 0)
	{
		nbr *= -1;
		return (1 + ft_nbrlen(nbr));
	}
	if ((nbr / 10) == 0)
		return (1);
	else
		return (1 + ft_nbrlen(nbr / 10));
}

void	formatting(t_d_flags flg, int d)
{
	if (flg.flg_p == 1 || flg.flg_sp == 1)
		flg.wdth--;
	if ((flg.wdth > flg.prec) && (flg.prec > ft_nbrlen(d)))
	{
		print_spaces(flg.wdth - flg.prec);
		(flg.flg_p != 0) ? write(1, "+", 1) :
			write(1, "-", 1);
		print_0(flg.prec - ft_nbrlen(d));
	}
}

void	ft_pf_putnbr(long long int n)
{
	long long int			temp;
	long long int			counter;
	unsigned long long int	nb;

	counter = 1;
	nb = n;
	if (n < 0)
		nb = -n;
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

void	p_m_chk(t_d_flags *flg, long long int d)
{
	if (flg->flg_p == 1)
		flg->flg_p = (d >= 0) ? write(1, "+", 1) : write(1, "-", 1);
	else if (flg->flg_sp == 1)
		write(1, " ", 1);
}

void	m_chk(t_d_flags flg, long long int d)
{
	if (flg.flg_n == 1)
	{
		p_m_chk(&flg, d);
		formatting(flg, d);
		print_spaces((flg.prec > ft_nbrlen(d)) ? (flg.wdth - flg.prec) :
				(flg.wdth - ft_nbrlen(d)));
	}
	else if (flg.flg_0 == 1 && flg.dot == 0)
	{
		p_m_chk(&flg, d);
		print_0(flg.wdth - ft_nbrlen(d));
		ft_pf_putnbr(d);
	}

}
