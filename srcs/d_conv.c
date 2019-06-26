/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:29:28 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/26 13:00:21 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_sh_lg		*check_h_l(const char *frm, int *i, va_list ap)
{
	int	index;
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
			d->lld = 1
		else if (frm[index] == 'l' && frm[index - 1] != 'l')
			d->ld = 1;
	}
	else
		d->d = 1;
	return (d);
}

void			d_conv(const char *frm, int *i, va_list ap, int *ret)
{
	int		flag;
	t_sh_lg		*d;

	flag = 0;
	d = check_h_l(frm, i, ap);
	if (d->d == 1)
		d->d = va_arg(ap, int);
	else if (d->hd == 1)
		d->hd = (short int)(va_arg(ap, int);
	else if (d->hhd == 1)
		d->hhd = (short short int)va_arg(ap, int);
	else if (d->ld == 1)
		d->ld = va_arg(ap, long int);
	else if (d->lld == 1)
		d->lld = va_arg(ap, long long int);
}
