/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_solv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:46:02 by oelbelam          #+#    #+#             */
/*   Updated: 2019/07/08 12:22:01 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int			ft_putstr_o(const char *s, t_flags flag)
{
	int	count;

	if (flag.hsh == 0 && flag.dot == 1 && flag.pr == 0 && (s[0] == '0' && s[1] == '\0') && flag.wd != 0)
	{
		write(1, " ", 1);
		return (1);
	}
	count = 0;
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}


int		ft_nbln_o(unsigned long long int d, t_flags flg)
{
	int len;

	len = 0;
	if (d == 0 && flg.dot == 1)
		return (0);
	if (d == 0)
		len++;
	while (d)
	{
		len++;
		d = d / 10;
	}
	return (len);
}


int		ft_pf_putnbr_o(unsigned long long n, t_flags flg)
{
	unsigned long long		temp;
	unsigned long long		counter;
	unsigned long long		nb;
	int						count;

	counter = 1;
	nb = n;
	count = 0;
	if (n == 0 && (flg.dot == 1 || flg.hsh == 1))
		return (0);
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

void		o_solv(t_flags flg, unsigned long long o, int *ret)
{
	if (flg.flg_n == 1)
	{
		if (flg.hsh == 1 && o != 0)
		{
			*ret += write (1, "0", 1);
			flg.pr -= 1;
		}
		*ret += print_0(flg.pr - (int)ft_strlen(ft_nbr_oct(o)));
		*ret += ft_putstr_o(ft_nbr_oct(o), flg);
		*ret += print_spaces((flg.pr > (int)ft_strlen(ft_nbr_oct(o))) ?
					(flg.wd - flg.pr) : (flg.wd - (int)ft_strlen(ft_nbr_oct(o))));
	}
	else if (flg.flg_0 == 1 && flg.dot == 0)
	{
		*ret += print_0(flg.wd - (int)ft_strlen(ft_nbr_oct(o)));
		*ret += ft_putstr_o(ft_nbr_oct(o), flg);
	}
	else if (flg.hsh == 1 && o != 0)
	{
		*ret += print_spaces((flg.pr > (int)ft_strlen(ft_nbr_oct(o))) ?
			(flg.wd - flg.pr - 1) :
			(flg.wd - (int)ft_strlen(ft_nbr_oct(o)) - 1));
		*ret += write(1, "0", 1);
		*ret += ft_putstr_o(ft_nbr_oct(o), flg);
	}
	else
	{
		*ret += print_spaces((flg.pr > (int)ft_strlen(ft_nbr_oct(o)) ? 
				(flg.wd - flg.pr) : 
				(flg.wd - (int)ft_strlen(ft_nbr_oct(o)))));
		*ret += print_0(flg.pr - (int)ft_strlen((ft_nbr_oct(o))));
		*ret += ft_putstr_o(ft_nbr_oct(o), flg);
	}
}
