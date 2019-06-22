/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:21:53 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/23 21:33:38 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (*src1 == *src2 && *src1 && *src2)
	{
		src1++;
		src2++;
	}
	if (*src1 != *src2)
		return ((int)(*src1 - *src2));
	return (0);
}
