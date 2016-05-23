/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:23:15 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:34:10 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char			*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	char		*map;

	i = 0;
	if (s && f)
	{
		map = (char *)malloc(ft_strlen(s) + 1);
		if (map)
		{
			while (s[i] != '\0')
			{
				map[i] = f((char)s[i]);
				i++;
			}
			map[i] = '\0';
		}
		return (map);
	}
	return (NULL);
}
