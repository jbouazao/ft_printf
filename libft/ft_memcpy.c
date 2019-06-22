/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 20:34:01 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/16 13:30:03 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*source;

	i = 0;
	dest = (char *)dst;
	source = (const char *)src;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
