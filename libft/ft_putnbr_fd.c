/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:19:39 by dbreton           #+#    #+#             */
/*   Updated: 2014/11/27 16:30:58 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

void		ft_putnbr_fd(int nb, int fd)
{
	int		i;

	i = 1;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	while ((nb / i) >= 10)
		i *= 10;
	while (i >= 1)
	{
		ft_putchar_fd(((nb / i) + 48), fd);
		nb %= i;
		i /= 10;
	}
}
