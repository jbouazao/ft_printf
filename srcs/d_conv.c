/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:29:28 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/26 12:34:51 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		*check_h_l(const char *frm, int *i, va_list ap)
{
	int					index;
	long long int		lld;
	long int			ld;
	int					d;

	index = *i;
	d = 0;
	while (frm[index + 1] != 'd')
		index++;
	if (frm[index] == 'l')
	{
		if (frm[index - 1] == 'l')
			lld = va_arg(ap, long long int);
		else if (frm[index] == 'l' && frm[index - 1] != 'l')
			ld = va_arg(ap, long int);
	}
	else
		d = va_arg(ap, int);
	return (d);
}

void			d_conv(const char *frm, int *i, va_list ap, int *ret)
{
	void	*d;

	d = check_h_l(frm, i, ap);
	printf("%d", 5);
}
