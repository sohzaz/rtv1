/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:27:43 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:27:27 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

void			*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = (void *)malloc(size);
	if (ptr)
	{
		ft_memset(ptr, 0, size);
		return (ptr);
	}
	else
		return (NULL);
}
