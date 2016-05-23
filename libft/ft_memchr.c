/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:44:02 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/12 16:24:11 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	srch;

	i = 0;
	srch = c;
	if (s)
	{
		while (i < n)
		{
			if (*((unsigned char *)s + i) == srch)
				return ((void *)s + i);
			i++;
		}
	}
	return (NULL);
}
