/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:38:58 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:39:00 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				tab_len(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

void			clear_tab(char **str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

char			almost_equal_relative(float a, float b)
{
	double		diff;
	double		largest;

	diff = fabs(a - b);
	a = fabs(a);
	b = fabs(b);
	largest = (b > a) ? b : a;
	return (diff <= largest * FLT_EPSILON);
}

void			line_validate(char ***tmp, int len)
{
	if (tab_len(*tmp) != len)
		ft_exit(3, "file content mismatch");
}

void			*secure_malloc(unsigned int len)
{
	void		*res;

	res = malloc(len);
	if (!res)
		ft_exit(4, "malloc failed");
	return (res);
}
