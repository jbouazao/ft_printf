/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:10:25 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/06/24 11:30:59 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			ft_putstr_s(const char *s, int pr)
{
	while (*s && pr)
	{
		write(1, s, 1);
		s++;
		pr--;
	}
}

static void			s_conv_n(t_s_conv pram, char *s)
{
	if (pram.width >= pram.pr)
	{
		if (pram.pr >= 0)
		{
			ft_putstr_s(s, pram.pr);
			if (ft_strlen(s) > (size_t)pram.pr)
				print_spaces(pram.width - pram.pr);
			else
				print_spaces(pram.width - ft_strlen(s));
		}
		else
		{
			ft_putstr(s);
			print_spaces(pram.width - ft_strlen(s));
		}
	}
	else if (pram.width < pram.pr)
		ft_putstr_s(s, pram.pr);
}

static void			s_conv_p(t_s_conv pram, char *s)
{
	if (pram.flag == '+' && pram.width >= pram.pr)
	{
		if (pram.pr >= 0)
		{
			if (ft_strlen(s) > (size_t)pram.pr)
				print_spaces(pram.width - pram.pr);
			else
				print_spaces(pram.width - ft_strlen(s));
			ft_putstr_s(s, pram.pr);
		}
		else
		{
			print_spaces(pram.width - ft_strlen(s));
			ft_putstr(s);
		}
	}
	else if (pram.flag == '+' && pram.width < pram.pr)
		ft_putstr_s(s, pram.pr);
	else if (pram.flag == '-')
		s_conv_n(pram, s);
}

void				s_conv(const char *frm, int *i, va_list ap)
{
	char		*s;
	t_s_conv	pram;
	char		*str;

	s = va_arg(ap, char*);
	str = (s == NULL) ? ft_strdup("(null)") : ft_strdup(s);
	if (frm[*i] == '-')
	{
		pram.flag = '-';
		(*i)++;
	}
	else
		pram.flag = '+';
	if ((frm[*i] >= '0' && frm[*i] <= '9'))
		pram.width = ft_atoi(&frm[*i]);
	else
		pram.width = 0;
	while (frm[*i] >= '0' && frm[*i] <= '9')
		(*i)++;
	if (frm[*i] == '.')
		pram.pr = ft_atoi(&frm[(*i + 1)]);
	else
		pram.pr = -1;
	s_conv_p(pram, str);
	free(str);
}
