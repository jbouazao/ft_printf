/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_perc_strct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:42:52 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/24 10:37:12 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			print_spaces(int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		write(1, " ", 1);
		i++;
	}
}

void			perc_flag(const char *format, int *i, va_list ap)
{
	write(1, &format[*i], 1);
	(*i)++;
}

const t_flags_struct g_struct_var =
{
	{ "%csd" },
	{ &perc_flag, &c_flag, &s_flag, &d_flag }
};

t_flags_struct	get_struct_var(void)
{
	return (g_struct_var);
}
