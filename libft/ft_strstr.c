/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:56:34 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/23 21:37:45 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	else
		while (haystack[i] != '\0')
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
				return (((char *)haystack) + i);
			i++;
		}
	return (NULL);
}
