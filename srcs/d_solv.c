/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_solv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:21:27 by jbouazao          #+#    #+#             */
/*   Updated: 2019/07/07 21:12:03 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nbln(long long int d, t_flags flg)
{
	int len;

	len = 0;
	if (d == 0 && flg.dot == 1)
		return (0);
	if (d < 0 || d == 0)
		len++;
	while (d)
	{
		len++;
		d = d / 10;
	}
	return (len);
}

int		ft_pf_putnbr(long long int n, t_flags flg)
{
	long long int			temp;
	long long int			counter;
	unsigned long long int	nb;
	int						count;

	counter = 1;
	nb = n;
	count = 0;
	if (n == 0 && flg.dot == 1)
		return (0);
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
		count++;
	}
	return (count);
}

int		p_m_chk(t_flags *flg, long long int d)
{
	int ret;

	ret = 0;
	if (flg->flg_p == 1)
	{
		flg->flg_p = (d >= 0) ? write(1, "+", 1) : write(1, "-", 1);
		ret += 1;
		flg->wd -= 1;
	}
	else if (flg->flg_sp == 1 && d >= 0)
	{
		ret += write(1, " ", 1);
		flg->wd -= 1;
	}
	else if (d < 0)
	{
		ret += write(1, "-", 1);
		flg->wd -= 1;
	}
	return (ret);
}

void	m_chk_c(t_flags flg, long long int d, int *ret)
{
	flg.wd -= (flg.flg_p == 1 || flg.flg_sp == 1 || d < 0) ? 1 : 0;
	if (d < 0)
		*ret += print_spaces(((flg.pr > ft_nbln(d, flg)) ?
					(flg.wd - flg.pr) : (flg.wd - ft_nbln(d, flg)) + 1));
	else
		*ret += print_spaces(((flg.pr > ft_nbln(d, flg)) ?
					(flg.wd - flg.pr) : (flg.wd - ft_nbln(d, flg))));
	*ret += p_m_chk(&flg, d);
	*ret += print_0((d >= 0) ? (flg.pr - ft_nbln(d, flg)) :
			flg.pr - ft_nbln(d, flg) + 1);
	*ret += ft_pf_putnbr(d, flg);
}

void	m_chk(t_flags flg, long long int d, int *ret)
{
	if (flg.flg_n == 1)
	{
		flg.wd += (d < 0) ? 1 : 0;
		*ret += p_m_chk(&flg, d);
		*ret += print_0((d >= 0) ? (flg.pr - ft_nbln(d, flg)) :
				flg.pr - ft_nbln(d, flg) + 1);
		*ret += ft_pf_putnbr(d, flg);
		if (d < 0)
			*ret += print_spaces((flg.pr > ft_nbln(d, flg)) ?
					(flg.wd - flg.pr - 1) : (flg.wd - ft_nbln(d, flg)));
		else
			*ret += print_spaces((flg.pr > ft_nbln(d, flg)) ?
					(flg.wd - flg.pr) : (flg.wd - ft_nbln(d, flg)));
	}
	else if (flg.flg_0 == 1 && flg.dot == 0)
	{
		*ret += p_m_chk(&flg, d);
		*ret += print_0((d >= 0) ? (flg.wd - ft_nbln(d, flg)) :
				(flg.wd - ft_nbln(d, flg) + 1));
		*ret += ft_pf_putnbr(d, flg);
	}
	else
		m_chk_c(flg, d, ret);
}
