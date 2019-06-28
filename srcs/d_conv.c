/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:29:28 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/28 15:00:42 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			check_h_l(const char *frm, int *i)
{
	int		index;
	int		flag_d;

	index = *i;
	flag_d = 0;
	while (frm[index + 1] != 'd')
		index++;
	if (frm[index] == 'h')
	{
		if (frm[index - 1] == 'h')
			flag_d = 1;
		else if (frm[index] == 'h' && frm[index - 1] != 'h')
			flag_d = 2;
	}
	if (frm[index] == 'l')
	{
		if (frm[index - 1] == 'l')
			flag_d = 3;
		else if (frm[index] == 'l' && frm[index - 1] != 'l')
			flag_d = 4;
	}
	else
		flag_d = 5;
	return (flag_d);
}

static int			assign_d(int flag_d, va_list ap)
{
	long long int d;

	d = 0;
	if (flag_d == 5)
		d = (int)va_arg(ap, int);
	else if (flag_d == 2)
		d = (short int)va_arg(ap, int);
	else if (flag_d == 1)
		d = (char)va_arg(ap, int);
	else if (flag_d == 4)
		d = va_arg(ap, long int);
	else if (flag_d == 3)
		d = va_arg(ap, long long int);
	return (d);
}

static t_d_flags	chck_flags(const char *frm, int *i)
{
	t_d_flags	flags;

	flags = init_d_flags();
	while ((frm[*i] <= '0' || frm[*i] > '9') && frm[*i] != 'd')
	{
		if (frm[*i] == '+')
			flags.flag_p = 1;
		if (frm[*i] == '-')
			flags.flag_n = 1;
		if (frm[*i] == ' ')
			flags.flag_sp = 1;
		if (frm[*i] == '0')
			flags.flag_0 = 1;
		(*i)++;
	}
	return (flags);
}

static void			wdth_prc(const char *frm, int *i, int *wdth, int *prec)
{
	while (frm[*i] != 'h' && frm[*i] != 'l' && frm[*i] != 'd')
	{
		if (frm[*i] >= '1' && frm[*i] <= '9')
		{
			*wdth = ft_atoi(&frm[*i]);
			while (frm[*i] != '.' && frm[*i] != 'd')
				(*i)++;
		}
		if (frm[*i] == '.')
		{
			*prec = ft_atoi(&frm[(*i) + 1]);
			break ;
		}
		(*i)++;
	}
	while (frm[*i] != 'd')
		(*i)++;
}

void				d_conv(const char *frm, int *i, va_list ap, int *ret)
{
	long long int	d;
	t_d_flags		flags;
	int				flag_d;
	*ret = 0;

	flag_d = check_h_l(frm, i);
	d = assign_d(flag_d, ap);
	flags = chck_flags(frm, i);
	wdth_prc(frm, i, &(flags.wdth), &(flags.prec));
	if (flags.flag_n == 1)

}
