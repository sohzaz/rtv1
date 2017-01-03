/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:12:40 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/10 14:58:17 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

int			ft_strcmp(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2 ) {
		return (-1);
	}
	while ((s1[i] != 0) && (s2[i]) && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
