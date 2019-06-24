/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:09:51 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/06/24 10:09:53 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void					c_flag(const char *frm, int *i, va_list ap)
{
	char	c;
	int		it;

	it = 0;
	c = va_arg(ap, int);
	if (frm[*i] == '-' && (frm[(*i) + 1] >= '1' && frm[(*i) + 1] <= '9'))
	{
		write(1, &c, 1);
		(*i)++;
		print_spaces(ft_atoi(&frm[*i]));
	}
	else if (frm[*i] >= '1' && frm[*i] <= '9')
	{
		print_spaces(ft_atoi(&frm[*i]) - 1);
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}
