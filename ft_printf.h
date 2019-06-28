/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:01:34 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/28 14:54:28 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct	s_d_flags
{
	int flag_p;
	int flag_n;
	int flag_sp;
	int flag_0;
	int	wdth;
	int prec;
}				t_d_flags;

/*typedef struct	s_sh_lg
{
	int				d;
	long int		ld;
	long long int	lld;
	short int		hd;
	char			hhd;
	long long int	number;
}				t_sh_lg;*/

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
//t_sh_lg			*init_d(void);
t_d_flags		init_d_flags(void);
void			d_conv(const char *frm, int *i, va_list ap, int *ret);

#endif
