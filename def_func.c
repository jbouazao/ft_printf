/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:19:51 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/22 15:54:12 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_spaces(int width)
{
	int i;

	i = 0;
	while (i < width - 1)
	{
		write(1, " ", 1);
		i++;
	}
}

void			pourc_flag(const char *format, int *i, va_list ap)
{
	write(1, &format[*i], 1);
	(*i)++;
}

void			c_flag(const char *frm, int *i, va_list ap)
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
		print_spaces(ft_atoi(&frm[*i]));
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}

void			d_flag(const char *format, int *i, va_list ap)
{
	write(1, " -test-D- ", 10);
}

const t_flags_struct g_struct_var =
{
	{ "%cd" },
	{ &pourc_flag, &c_flag, &d_flag }
};

t_flags_struct	get_struct_var(void)
{
	return (g_struct_var);
}
