/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:01:34 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/23 13:01:09 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef	struct	s_s_conv
{
	char	flag;
	int		width;
	int		pr;
}				t_s_conv;

typedef struct	s_flags_struct
{
	char	flag[11];
	void	(*flag_func[11])(const char *format, int *index, va_list ap);
}				t_flags_struct;

t_flags_struct	get_struct_var();
void			print_spaces(int width);
void			perc_flag(const char *format, int *i, va_list ap);
void			c_flag(const char *frm, int *i, va_list ap);
void			s_flag(const char *format, int *i, va_list ap);
void			p_flag(const char *format, int *i, va_list ap);
void			d_flag(const char *format, int *i, va_list ap);

#endif
