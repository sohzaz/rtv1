/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:58:58 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/03 15:23:47 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void					*ft_memset(void *b, int c, size_t len)
{
	unsigned int		i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = c;
		i++;
	}
	return (b);
}
