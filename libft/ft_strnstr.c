/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:43:54 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:36:52 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char				*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	int				j;

	i = 0;
	j = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
		if (s2[j] == '\0')
			return ((char *)s1 + (i - (j - 1)));
		i++;
	}
	return (NULL);
}
