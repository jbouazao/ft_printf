/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:08:40 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/25 23:16:56 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		len;

	if (!s2 || !s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tab = (char *)malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (*s1)
	{
		tab[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	tab[i] = '\0';
	return (tab);
}
