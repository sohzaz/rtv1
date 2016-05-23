/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:16:16 by dbreton           #+#    #+#             */
/*   Updated: 2015/03/16 07:16:14 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char			*ft_strtrim(char const *s)
{
	size_t		i;
	char		*trim;
	int			max;

	i = 0;
	if (s)
	{
		trim = (char *)malloc(ft_strlen(s) + 1);
		max = ft_strlen(s) - 1;
		if ((s[0] || s[max]) != (' ' | '\n' | '\t'))
			trim = ft_strcpy(trim, s);
		if (trim)
		{
			while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i++;
			while (s[max] == ' ' || s[max] == '\n' || s[max] == '\t')
				max--;
			if (i != ft_strlen(s))
				trim = ft_strsub(s, i, max - i + 1);
		}
		return (trim);
	}
	return (NULL);
}
