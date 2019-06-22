/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:41:44 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/17 17:58:02 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*begin;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i != start)
	{
		i++;
		s++;
	}
	begin = str;
	while (len)
	{
		*str = *s;
		str++;
		s++;
		len--;
	}
	*str = '\0';
	return (begin);
}
