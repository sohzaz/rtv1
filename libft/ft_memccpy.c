/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:33:13 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/05 14:07:50 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t			i;
	unsigned char	conv;

	i = 0;
	conv = c;
	while ((i < n) && (*((unsigned char *)src + i) != conv))
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	if (*((unsigned char *)src + i) == conv)
	{
		*((unsigned char *)dst + i) = conv;
		return (dst + i + 1);
	}
	else
		return (NULL);
}
