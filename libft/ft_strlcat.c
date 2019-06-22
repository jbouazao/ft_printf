/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:02:21 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/27 23:29:29 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	int		i;
	size_t	ret;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	else
	{
		ret = len_dst + len_src;
		while (src[i] != '\0' && len_dst + 1 < size)
		{
			dst[len_dst] = src[i];
			len_dst++;
			i++;
		}
		dst[len_dst] = '\0';
	}
	return (ret);
}
