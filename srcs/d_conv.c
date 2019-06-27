/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:29:28 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/27 16:14:01 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_sh_lg		*check_h_l(const char *frm, int *i)
{
	int		index;
	t_sh_lg	*d;

	index = *i;
	while (frm[index + 1] != 'd')
		index++;
	d = init_d();
	if (frm[index] == 'h')
	{
		if (frm[index - 1] == 'h')
			d->hhd = 1;
		else if (frm[index] == 'h' && frm[index - 1] != 'h')
			d->hd = 1;
	}
	if (frm[index] == 'l')
	{
		if (frm[index - 1] == 'l')
			d->lld = 1;
		else if (frm[index] == 'l' && frm[index - 1] != 'l')
			d->ld = 1;
	}
	else
		d->d = 1;
	return (d);
}

static void			assign_d(t_sh_lg *d, va_list ap)
{
	if (d->d == 1)
		d->d = va_arg(ap, int);
	else if (d->hd == 1)
		d->hd = (short int)va_arg(ap, int);
	else if (d->hhd == 1)
		d->hhd = (char)va_arg(ap, int);
	else if (d->ld == 1)
		d->ld = va_arg(ap, long int);
	else if (d->lld == 1)
		d->lld = va_arg(ap, long long int);
}

static t_d_flags	chck_flags(const char *frm, int *i)
{
	t_d_flags	flags;
	int			tp_i;

	flags = init_d_flags(void);
	tp_i = *i;
	while (frm[tp_i] <= 0 || frm[tp_i] >= 9)
	{
		if (frm[tp_i] == '+')
			flags.flag_p = 1;
		if (frm[tp_i] == '-')
			flags.flag_n = 1;
		if (frm[tp_i] == ' ')
			flags.flag_sp = 1;
		tp_i++;
	}
	if (frm[tp_i] == '0')
		flags.flag_0 = 1;
	return (flags);
}

static void			wdth_prc(int *wdth, int *prc, const char *frm, t_sh_lg *d)
{
	int index;

	index = *i;
	if (!(wdth = (int *)malloc(sizeof(int))))
		return (NULL);
	if (!(prec = (int *)malloc(sizeof(int))))
		return (NULL);
	while ()
}

void				d_conv(const char *frm, int *i, va_list ap, int *ret)
{
	t_sh_lg		*d;
	t_d_flags	flags;
	int			*wdth;
	int			*prec;

	d = check_h_l(frm, i);
	assign_d(d, ap);
	flags = chck_flags(frm, i);
	wdth_prc(wdth, prec);
	if(flags.flag_n == 1)
	{
		
	}
}
