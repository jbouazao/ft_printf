/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:23:04 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/22 18:29:08 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	flag;

	value = 0;
	flag = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		flag = 1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str >= '0' && *str <= '9')
		while (*str && (*str >= '0' && *str <= '9'))
		{
			value = (value * 10) + (int)(*str - '0');
			str++;
		}
	(flag) ? value *= -1 : value;
	return (value);
}
