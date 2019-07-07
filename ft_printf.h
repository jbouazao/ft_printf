/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:01:34 by jbouazao          #+#    #+#             */
/*   Updated: 2019/07/07 22:28:20 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"
# include <limits.h>

typedef struct	s_flags
{
	int flg_p;
	int flg_n;
	int flg_sp;
	int flg_0;
	int	wd;
	int pr;
	int	dot;
	int hsh;
}				t_flags;

typedef	struct	s_s_conv
{
	char	flag;
	int		width;
	int		pr;
}				t_s_conv;

typedef struct	s_flags_struct
{
	char	flag[11];
	void	(*flg_ft[11])(const char *frm, int *i, va_list ap, int *ret);
}				t_flags_struct;

t_flags_struct	get_struct_var();
int				print_spaces(int width);
void			perc_conv(const char *frm, int *i, va_list ap, int *ret);
void			c_conv(const char *frm, int *i, va_list ap, int *ret);
void			s_conv(const char *format, int *i, va_list ap, int *ret);
void			p_conv(const char *format, int *i, va_list ap, int *ret);
void			o_conv(const char *frm, int *i, va_list ap, int *ret);
t_flags			init_flags(void);
void			d_conv(const char *frm, int *i, va_list ap, int *ret);
int				print_0(int wdth);
void			m_chk(t_flags flg, long long int d, int *ret);
unsigned long long				ft_nbr_oct(unsigned long long nbr);
int				ft_pf_putnbr_o(unsigned long long n, t_flags flg);
void			o_solv(t_flags flg, unsigned long long o, int *ret);

#endif
