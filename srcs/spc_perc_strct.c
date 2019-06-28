/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_perc_strct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:42:52 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/28 14:54:09 by jbouazao         ###   ########.fr       */
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
	{ &perc_conv, &c_conv, &s_conv, &d_conv }
};

t_flags_struct	get_struct_var(void)
{
	return (g_struct_var);
}

/*t_sh_lg			*init_d()
{
	t_sh_lg	*d;

	if (!(d = (t_sh_lg *)malloc(sizeof(t_sh_lg))))
		return (NULL);
	d->d = 0;
	d->hd = 0;
	d->hhd = 0;
	d->ld = 0;
	d->lld = 0;
	return (d);
}*/

t_d_flags		init_d_flags(void)
{
	t_d_flags	flags;

	flags.flag_p = 0;
	flags.flag_n = 0;
	flags.flag_sp = 0;
	flags.flag_0 = 0;
	flags.wdth = 0;
	flags.prec = 0;
	return (flags);
}
