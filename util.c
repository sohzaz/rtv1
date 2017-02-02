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

#include "fractol.h"

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
char			almost_equal_relative(float A, float B)
{
	float		diff;
	float 		largest;

	diff = fabs(A - B);
	A = fabs(A);
	B = fabs(B);
	largest = (B > A) ? B : A;
	return (diff <= largest * FLT_EPSILON);
}
