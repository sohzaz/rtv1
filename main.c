/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 10:27:23 by dbreton           #+#    #+#             */
/*   Updated: 2016/05/16 15:31:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		get_usage(void)
{
	write(2, "Usage: ./fractol [123]\n", 23);
	write(2, "1\tMandelbrot Set\n", 17);
	write(2, "2\tJulia Set\n", 12);
	write(2, "3\tSierpinski carpet\n", 20);
}

int			main(int ac, char **av)
{
	t_mlx	        s;
	int             fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		parse(&s, fd);
        win_init(s);
	}
	get_usage();
	return (0);
}
