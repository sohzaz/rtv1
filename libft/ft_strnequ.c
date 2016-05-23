/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:03:04 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:35:48 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 && s2)
	{
		i = ft_strncmp(s1, s2, n);
		if (i != 0)
			i = 0;
		else
			i = 1;
	}
	return (i);
}
