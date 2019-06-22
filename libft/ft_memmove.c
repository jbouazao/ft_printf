/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 21:21:34 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/20 19:06:57 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t	temp;

	source = (char *)src;
	dest = (char *)dst;
	if (source < dest)
	{
		temp = len;
		while (temp > 0)
		{
			dest[temp - 1] = source[temp - 1];
			temp--;
		}
	}
	else
	{
		temp = 0;
		while (temp < len)
		{
			dest[temp] = source[temp];
			temp++;
		}
	}
	return (dst);
}
