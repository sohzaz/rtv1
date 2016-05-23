/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:58:04 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/12 16:34:05 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <string.h>

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	int			j;
	char		*sub;

	i = start;
	j = 0;
	if (s)
	{
		sub = (char *)malloc(len + 1);
		if (sub)
		{
			while (i < (start + len) && s[i] != '\0')
			{
				sub[j] = s[i];
				i++;
				j++;
			}
			sub[j] = '\0';
			return (sub);
		}
	}
	return (NULL);
}
