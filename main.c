/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:24:09 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 16:24:21 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		get_usage(void)
{
	ft_putstr_fd("Usage : ./RTv1 <file>\n", 2);
}

int			main(int ac, char **av)
{
	t_mlx	s;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
		{
			parse(&s, fd);
			win_init(s);
		}
	}
	get_usage();
	return (0);
}
