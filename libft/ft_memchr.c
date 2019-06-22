/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 19:12:58 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/21 16:06:22 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	size_t			i;

	source = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
		{
			return ((unsigned char *)s);
		}
		s++;
		i++;
	}
	return (NULL);
}
