/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:46:25 by jbouazao          #+#    #+#             */
/*   Updated: 2019/07/04 11:25:40 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		det_flag(const char *format, int *i, va_list ap, int *ret)
{
	int				it;
	t_flags_struct	struct_tobe_man;
	int				old_index;

	old_index = *i;
	struct_tobe_man = get_struct_var();
	while (format[*i])
	{
		it = 0;
		while (it < 4)
		{
			if (struct_tobe_man.flag[it] == format[*i])
			{
				struct_tobe_man.flg_ft[it](format, &old_index, ap, ret);
				return ;
			}
			it++;
		}
		(*i)++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			det_flag(format, &i, ap, &ret);
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}
int 		main(void)
{
	printf("\nret = %d\n", ft_printf("%.5lld|%-.5lld|%+.5lld|% .5lld|%0.5lld", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN));
	//printf("\nret ---> %d\n",printf(("%1.5lld|%));
	/*printf("\nret = %d", printf("%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d", 0, 0, 0, 0, 0, 0, 0));*/
	/*ft_printf("|%5.d|", -0);
	printf("\n|%5.d|", -0);*/
}
