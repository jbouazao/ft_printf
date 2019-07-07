/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:10:25 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/07 21:13:50 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			ft_putstr_s(const char *s, int pr)
{
	int	count;

	count = 0;
	while (*s && pr)
	{
		count += write(1, s, 1);
		s++;
		pr--;
	}
	return (count);
}

static void			s_conv_n(t_s_conv pram, char *s, int *ret)
{
	if (pram.width >= pram.pr)
	{
		if (pram.pr >= 0)
		{
			*ret += ft_putstr_s(s, pram.pr);
			if (ft_strlen(s) > (size_t)pram.pr)
				*ret += print_spaces(pram.width - pram.pr);
			else
				*ret += print_spaces(pram.width - ft_strlen(s));
		}
		else
		{
			*ret += ft_putstr_s(s, (int)ft_strlen(s));
			*ret += print_spaces(pram.width - ft_strlen(s));
		}
	}
	else if (pram.width < pram.pr)
	{
		*ret += ft_putstr_s(s, pram.pr);
		*ret += print_spaces(pram.width - ft_strlen(s));
	}
}

static void			s_conv_p(t_s_conv pram, char *s, int *ret)
{
	if (pram.flag == '+' && pram.width >= pram.pr)
	{
		if (pram.pr >= 0)
		{
			if (ft_strlen(s) > (size_t)pram.pr)
				*ret += print_spaces(pram.width - pram.pr);
			else
				*ret += print_spaces(pram.width - ft_strlen(s));
			*ret += ft_putstr_s(s, pram.pr);
		}
		else
		{
			*ret += print_spaces(pram.width - ft_strlen(s));
			*ret += ft_putstr_s(s, (int)ft_strlen(s));
		}
	}
	else if (pram.flag == '+' && pram.width < pram.pr)
	{
		*ret += print_spaces(pram.width - ft_strlen(s));
		*ret += ft_putstr_s(s, pram.pr);
	}
	else if (pram.flag == '-')
		s_conv_n(pram, s, ret);
}

void				s_conv(const char *frm, int *i, va_list ap, int *ret)
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
	s_conv_p(pram, str, ret);
	free(str);
}
