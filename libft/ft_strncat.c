/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:53:01 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:35:03 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

char			*ft_strncat(char *s1, char const *s2, size_t n)
{
	int			i;
	size_t		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while ((s2[j] != '\0') && (j < n))
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
