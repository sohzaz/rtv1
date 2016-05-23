/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:11:40 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:37:16 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char		*ft_strrchr(char const *s, int c)
{
	size_t	i;
	char	srch;

	srch = c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == srch)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
