/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:32:54 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/12 12:34:29 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (n > 0 && s1 && s2)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
		n--;
	}
	return (0);
}
