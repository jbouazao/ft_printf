/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:45:58 by jbouazao          #+#    #+#             */
/*   Updated: 2018/10/23 15:54:10 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;
	size_t	lens;

	i = 0;
	temp = (char *)s;
	lens = ft_strlen(s) + 1;
	while (lens--)
	{
		if (temp[lens] == (unsigned char)c)
		{
			return (temp + lens);
		}
	}
	return (NULL);
}
