/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:28:13 by jbouazao          #+#    #+#             */
/*   Updated: 2018/11/09 18:33:58 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	temp = (void*)malloc(size);
	if (temp)
		return (ft_memset(temp, 0, size));
	else
		return (NULL);
}
