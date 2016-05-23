/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:43:29 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:36:31 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

char			*ft_strnew(size_t size)
{
	char		*str;

	str = (char *)malloc(size);
	if (str)
	{
		ft_memset(str, size, '\0');
		return (str);
	}
	else
		return (NULL);
}
