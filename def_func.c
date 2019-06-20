/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:19:51 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/20 21:24:05 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			c_flag(const char *format, int i)
{
	printf("   --c_flag works--   ");
}

void			d_flag(const char *format, int i)
{
	printf("--d_flag works--");
}

const t_flags_struct g_struct_var =
{
	{ "cd" },
	{ &c_flag, &d_flag }
};

t_flags_struct	get_struct_var(void)
{
	return (struct_var);
}
