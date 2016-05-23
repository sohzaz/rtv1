/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:36:50 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/03 14:58:02 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strdup(char const *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = (char*)malloc(i + 1);
	if (s2)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
