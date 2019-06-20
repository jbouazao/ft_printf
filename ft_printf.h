/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:01:34 by jbouazao          #+#    #+#             */
/*   Updated: 2019/06/20 21:01:07 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "./libft/libft.h"

typedef struct	s_flags_struct
{
	char	flag[10];
	void	(*flag_func[10])(const char *format, int index);
}				t_flags_struct;

t_flags_struct	get_struct_var();

#endif
