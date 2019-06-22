/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:36:17 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/23 14:14:23 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*src;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	src = (char *)malloc(sizeof(char) * len + 1);
	if (!src)
		return (NULL);
	while (i < len)
	{
		src[i] = s1[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
