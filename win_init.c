/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 19:15:07 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/22 18:04:00 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int			expose_hook(t_mlx *s)
{
	if (s->need_refresh)
	{
		render_pic(s);
		s->need_refresh = 0;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

void		win_init(t_mlx s)
{
	if ((s.mlx = mlx_init()) != NULL)
	{
		s.win = mlx_new_window(s.mlx, WIN_MAX_X, WIN_MAX_Y, "42 RTv1");
		s.img = mlx_new_image(s.mlx, WIN_MAX_X, WIN_MAX_Y);
		if (s.win && s.img)
		{
			s.need_refresh = 1;
			mlx_expose_hook(s.win, &expose_hook, &s);
			mlx_loop(s.mlx);
		}
	}
}
