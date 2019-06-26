/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_perc_strct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:42:52 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/25 11:51:15 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				print_spaces(int width)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < width)
	{
		count += write(1, " ", 1);
		i++;
	}
	return (count);
}

void			perc_conv(const char *format, int *i, va_list ap, int *ret)
{
	(void)ap;
	ret += write(1, &format[*i], 1);
	(*i)++;
}

const t_flags_struct g_struct_var =
{
	{ "%csd" },
	{ &perc_conv, &c_conv, &s_conv }
};

t_flags_struct	get_struct_var(void)
{
	return (g_struct_var);
}
