/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:47:28 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/17 16:14:12 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*begin;

	if (!s)
		return (NULL);
	str = (char*)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	begin = str;
	while (*s)
	{
		*str = f(*s);
		s++;
		str++;
	}
	*str = '\0';
	return (begin);
}
