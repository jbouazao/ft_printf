/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:22:55 by oelbelam          #+#    #+#             */
/*   Updated: 2019/07/08 11:21:06 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"


static int			check_hl_o(const char *frm, int *i)
{
	int		index;
	int		flag_o;

	index = *i;
	flag_o = 0;
	while (frm[index + 1] != 'o')
		index++;
	if (frm[index] == 'h')
	{
		if (frm[index - 1] == 'h')
			flag_o = 1;
		else if (frm[index] == 'h' && frm[index - 1] != 'h')
			flag_o = 2;
	}
	if (frm[index] == 'l')
	{
		if (frm[index - 1] == 'l')
			flag_o = 3;
		else if (frm[index] == 'l' && frm[index - 1] != 'l')
			flag_o = 4;
	}
	else
		flag_o = 5;
	return (flag_o);
}

static unsigned long long			assign_o(int flag_d, va_list ap)
{
	unsigned long long int	o;

	o = 0;
	if (flag_d == 5)
		o = (unsigned int)va_arg(ap, int);
	else if (flag_d == 2)
		o = (unsigned short)va_arg(ap, int);
	else if (flag_d == 1)
		o = (unsigned char)va_arg(ap, int);
	else if (flag_d == 4)
		o = (unsigned long)va_arg(ap, long int);
	else if (flag_d == 3)
		o = (unsigned long long)va_arg(ap,  long long int);
	return (o);
}

static t_flags	chck_flags_o(const char *frm, int *i)
{
	t_flags	flags;

	flags = init_flags();
	while (frm[*i] != 'o' && frm[*i] != '.')
	{
		if (frm[*i] >= '1' && frm[*i] <= '9')
			return (flags);
		if (frm[*i] == '-')
			flags.flg_n = 1;
		if (frm[*i] == '0')
			flags.flg_0 = 1;
		if (frm[*i] == '#')
			flags.hsh = 1;
		(*i)++;
	}
	return (flags);
}

static void			wdth_prc_o(const char *frm, int *i, t_flags *flags)
{
	while (frm[*i] != 'h' && frm[*i] != 'l' && frm[*i] != 'o' && frm[*i])
	{
		if (frm[*i] >= '1' && frm[*i] <= '9')
		{
			flags->wd = ft_atoi(&frm[*i]);
			while (frm[*i] != '.' && frm[*i] != 'o')
				(*i)++;
		}
		if (frm[*i] == '.')
		{
			flags->dot = 1;
			flags->pr = ft_atoi(&frm[(*i) + 1]);
			break ;
		}
	}
	while (frm[*i] != 'o')
		(*i)++;
}

void	o_conv(const char *frm, int *i, va_list ap, int *ret)
{
	t_flags				flg;
	unsigned long long	o;
	int					flag_o;
	
	flag_o = check_hl_o(frm, i);
	o = assign_o(flag_o, ap);
	flg = chck_flags_o(frm, i);
	wdth_prc_o(frm, i, &flg);
	o_solv(flg, o, ret);
}
