/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:55:31 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/09 00:11:35 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	else
		while (haystack[i] != '\0' && i < len)
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
				if ((len - i) >= ft_strlen(needle))
					return ((char *)haystack + i);
			i++;
		}
	return (NULL);
}
