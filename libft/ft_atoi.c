/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:21:49 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/12 14:55:31 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(char const *str)
{
	int			res;
	int			j;
	int			neg;

	j = 0;
	res = 0;
	neg = 1;
	while ((str[j] >= 9) && (str[j] <= 13 || str[j] == ' '))
		j++;
	if (str[j] == '-')
	{
		neg = -1;
		j++;
	}
	else if (str[j] == '+')
		j++;
	while (str[j] >= '0' && str[j] <= '9')
	{
		res = res * 10 + (str[j] - 48);
		j++;
	}
	if (neg == -1)
		res *= -1;
	return (res);
}
