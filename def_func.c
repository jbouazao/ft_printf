/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:19:51 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/22 13:25:48 by jbouazao         ###   ########.fr       */
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

int				count_width(const char *format, int *i)
{
	int width;
	
	width = 0;
	while (format[*i] >= '0' && format[*i] <= '9' && width < 2147483647)
	{
		width = (width * 10) + format[*i] - 48;
		(*i)++;
	}
	return (width);
}

void			pourc_flag(const char *format, int *i, va_list ap)
{
	write(1, &format[*i], 1);
	(*i)++;
}

void			c_flag(const char *format, int *i, va_list ap)
{
	char	c;
	int		width;
	int		it;

	width = 0;
	it = 0;
	c = va_arg(ap, int);
	if (format[*i] == '-' && (format[(*i) + 1] >= '1' && format[(*i) + 1] <= '9'))
	{
		write(1, &c, 1);
		(*i)++;
		width = count_width(format, i);
		print_spaces(width);
	}
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
