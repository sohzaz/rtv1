/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:49:38 by dbreton           #+#    #+#             */
/*   Updated: 2015/03/16 12:47:44 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void		*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*tmp;

	if (dst && src)
	{
		tmp = (char *)malloc(sizeof(char *) * len);
		if (tmp)
		{
			tmp = ft_strncpy(tmp, src, len);
			dst = ft_strncpy(dst, tmp, len);
			free(tmp);
		}
	}
	return (dst);
}
