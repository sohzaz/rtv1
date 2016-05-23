/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:08:07 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/12 14:55:21 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void		fillnbr(int n, int j, int neg, char *nbr)
{
	int			i;

	i = 0;
	if (neg == -1)
		nbr[i++] = '-';
	while (j >= 1)
	{
		nbr[i] = ((n / j) * neg) + 48;
		n %= j;
		j /= 10;
		i++;
	}
	nbr[i] = '\0';
}

char			*ft_itoa(int n)
{
	int			i;
	int			j;
	char		*nbr;
	int			neg;

	j = 1;
	i = 0;
	neg = 1;
	if (n < 0)
		neg = -1;
	while ((n / j) * neg > 9)
	{
		j *= 10;
		i++;
	}
	nbr = (char *)malloc(i + 2);
	if (nbr)
	{
		if (n == -2147483648)
			nbr = "-2147483648";
		else
			fillnbr(n, j, neg, nbr);
	}
	return (nbr);
}
