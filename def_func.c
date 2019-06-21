/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:19:51 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/21 22:02:35 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				count_width(const char *format, int *i)
{
	int width;
	
	width = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		width = (width * 10) + format[*i] - 48;
		(*i)++;
	}
	return (width);
}

void			pourc_flag(const char *format, int i, va_list ap)
{
	write(1, &format[i], 1);
}

void			c_flag(const char *format, int i, va_list ap)
{
	char	c;
	int		width;

	width = 0;
	c = va_arg(ap, int);
	if (format[i] == '-' && (format[i + 1] >= '1' && format[i + 1] <= '9'))
	{
		i++;
		width = count_width(format, &i);
	}
}	

void			d_flag(const char *format, int i, va_list ap)
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
