/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:37:22 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:34:29 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	i = 0;
	if (s && f)
	{
		map = (char*)malloc(ft_strlen(s) + 1);
		if (map)
		{
			while (s[i] != '\0')
			{
				map[i] = f(i, (char)s[i]);
				i++;
			}
			map[i] = '\0';
			return (map);
		}
	}
	return (NULL);
}
