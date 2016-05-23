/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:24:59 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:33:04 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str)
		{
			while (s1[j] != '\0')
				str[i++] = s1[j++];
			j = 0;
			while (s2[j] != '\0')
				str[i++] = s2[j++];
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
