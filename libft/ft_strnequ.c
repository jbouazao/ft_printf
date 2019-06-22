/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:36:04 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/17 16:40:27 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	temp;

	if (s1 && s2)
		while ((*s1 || *s2) && n)
		{
			temp = *s1 - *s2;
			if (temp < 0 || temp > 0)
				return (0);
			s1++;
			s2++;
			n--;
		}
	return (1);
}
