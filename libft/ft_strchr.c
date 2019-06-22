/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:59:59 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/23 18:55:09 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i <= ft_strlen(s))
	{
		if (temp[i] == (unsigned char)c)
		{
			return ((char *)temp + i);
		}
		else
		{
			i++;
		}
	}
	return (NULL);
}
