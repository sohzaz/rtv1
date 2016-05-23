/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:53:16 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:35:22 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char			*ft_strncpy(char *dst, char const *src, size_t n)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	if (ft_strlen(src) < n)
	{
		while (i < n)
		{
			dst[i] = '\0';
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
