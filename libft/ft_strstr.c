/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:43:54 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:39:18 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char			*ft_strstr(char const *s1, char const *s2)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	if (s1 && s2)
	{
		while (s1[i])
		{
			if (s1[i] == s2[j])
				j++;
			else
				j = 0;
			if (s2[j] == '\0')
				return ((char *)s1 + (i - (j - 1)));
			i++;
		}
	}
	return (NULL);
}
