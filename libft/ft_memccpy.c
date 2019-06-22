/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:00:14 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/16 20:39:16 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	source = (const unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dest[i] = (unsigned char)source[i];
		if (dest[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
