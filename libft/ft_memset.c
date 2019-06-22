/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 12:32:00 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/16 11:37:38 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t len)
{
	size_t			i;
	unsigned char	*dest1;

	i = 0;
	dest1 = (unsigned char *)dest;
	while (i < len)
	{
		dest1[i] = (unsigned char)value;
		i++;
	}
	return ((unsigned char *)dest1);
}
