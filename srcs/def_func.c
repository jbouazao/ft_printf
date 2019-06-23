/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:19:51 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/23 11:47:22 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void					c_flag(const char *frm, int *i, va_list ap)
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
		print_spaces(ft_atoi(&frm[*i]) - 1);
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}

static	void			ft_putstr_s(char const *s, int pr)
{
	int a;

	a = pr;
	if (s)
		while (*s && a)
		{
			write(1, s, 1);
			s++;
			a--;
		}
}

static	void			s_flags_m(t_to_c pram, char *s)
{
	if (pram.flag == '-')
	{
		if (pram.width >= pram.pr)
		{
			if (pram.pr >= 0)
			{
				ft_putstr_s(s, pram.pr);
				if (ft_strlen(s) > pram.pr)
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
		{
			ft_putstr_s(s, pram.pr);
			print_spaces(pram.width - ft_strlen(s));
		}
	}
}

static	void			s_flags_p(t_to_c pram, char *s)
{
	if (pram.flag == '+')
	{
		if (pram.width >= pram.pr)
		{
			if (pram.pr >= 0)
			{
				if (ft_strlen(s) > pram.pr)
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
		else if (pram.width < pram.pr)
		{
			print_spaces(pram.width - ft_strlen(s));
			ft_putstr_s(s, pram.pr);
		}
	}
	s_flags_m(pram, s);
}

void					s_flag(const char *frm, int *i, va_list ap)
{
	char	*s;
	t_to_c	pram;

	if (va_arg(ap, char*) == NULL)
		s = "(null)";
	else
		s = va_arg(ap, char*);
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
	s_flags_p(pram, s);
}
