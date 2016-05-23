/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:41:26 by dbreton           #+#    #+#             */
/*   Updated: 2015/03/16 07:11:44 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t			i;
	size_t			j;
	size_t			dst_size;

	i = 0;
	j = 0;
	dst_size = 0;
	if (dst && src)
	{
		while (dst[i] != '\0' && i < size)
			i++;
		if (i == size)
			return (ft_strlen(src) + i);
		else
		{
			dst_size = i;
			while (src[j] != '\0' && j < (size - dst_size - 1))
				dst[i++] = src[j++];
			dst[i] = '\0';
		}
	}
	return (dst_size + ft_strlen(src));
}
