/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_perc_strct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:42:52 by jbouazao          #+#    #+#             */
/*   Updated: 2019/07/07 21:51:05 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int				print_0(int width)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < width)
	{
		count += write(1, "0", 1);
		i++;
	}
	return (count);
}

int				print_spaces(int width)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (0 < width)
	{
		count += write(1, " ", 1);
		width--;
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
	{ "%csdo" },
	{ &perc_conv, &c_conv, &s_conv, &d_conv, &o_conv }
};

t_flags_struct	get_struct_var(void)
{
	return (g_struct_var);
}

t_flags		init_flags(void)
{
	t_flags	flags;

	flags.flg_p = 0;
	flags.flg_n = 0;
	flags.flg_sp = 0;
	flags.flg_0 = 0;
	flags.wd = 0;
	flags.pr = 0;
	flags.dot = 0;
	flags.hsh = 0;
	return (flags);
}
