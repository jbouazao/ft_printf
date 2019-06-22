/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:51:36 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/25 23:22:21 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;

	if (!s)
		return (NULL);
	end = (char *)s + ft_strlen(s) - 1;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	start = (char *)s;
	while (*end == ' ' || *end == '\n' || *end == '\t')
		end--;
	start = ft_strsub(s, 0, ft_strlen(s) - (ft_strlen(end) - 1));
	return (start);
}
