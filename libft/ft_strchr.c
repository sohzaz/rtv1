/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:03:35 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:11:25 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	srch;

	srch = c;
	i = 0;
	if (s)
	{
		while (s[i] != srch && s[i] != '\0')
			i++;
		if (s[i] == srch)
			return ((char *)&s[i]);
	}
	return (NULL);
}
