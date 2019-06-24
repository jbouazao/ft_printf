/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:46:25 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/24 10:44:39 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		det_flag(const char *format, int *i, va_list ap)
{
	int				it;
	t_flags_struct	struct_tobe_man;
	int				old_index;

	old_index = *i;
	struct_tobe_man = get_struct_var();
	while (format[*i])
	{
		it = 0;
		while (it < 3)
		{
			if (struct_tobe_man.flag[it] == format[*i])
			{
				struct_tobe_man.flag_func[it](format, &old_index, ap);
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

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			det_flag(format, &i, ap);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return(1);
}
int main()
{
	ft_printf("%c",'f');
}
