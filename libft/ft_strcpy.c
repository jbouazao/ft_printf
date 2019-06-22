/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:20:42 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/21 18:35:51 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(src);
	while (i < len + 1)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
