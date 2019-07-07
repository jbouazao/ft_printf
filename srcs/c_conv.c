/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:09:51 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/07 21:14:16 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void					c_conv(const char *frm, int *i, va_list ap, int *ret)
{
	char	c;
	int		it;

	it = 0;
	c = va_arg(ap, int);
	if (frm[*i] == '-' && (frm[(*i) + 1] >= '1' && frm[(*i) + 1] <= '9'))
	{
		*ret += write(1, &c, 1);
		(*i)++;
		*ret += print_spaces(ft_atoi(&frm[*i]) - 1);
	}
	else if (frm[*i] >= '1' && frm[*i] <= '9')
	{
		*ret += print_spaces(ft_atoi(&frm[*i]) - 1);
		*ret += write(1, &c, 1);
	}
	else
		*ret += write(1, &c, 1);
}
