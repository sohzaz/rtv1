/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:49:56 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/05 10:30:58 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}
