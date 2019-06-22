/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:19:30 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/09 18:39:48 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *temp;

	temp = NULL;
	temp = (char*)malloc(size + 1);
	if (temp)
		return (ft_memset(temp, '\0', size + 1));
	else
		return (NULL);
}
