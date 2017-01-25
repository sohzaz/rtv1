/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:39:09 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/22 18:15:28 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_zoom_handler(int btn, int x, int y, t_mlx *s)
{
	s->zoom = (s->zoom <= 50) ? 50 : s->zoom;
	if (btn == 4)
	{
		s->x_start += (s->x_start - x) / (s->zoom / (s->zoom / 3));
		s->y_start += (s->y_start - y) / (s->zoom / (s->zoom / 3));
		s->zoom += s->zoom / 3;
	}
	else if (btn == 5)
	{
		s->x_start -= (s->x_start - x) / (s->zoom / (s->zoom / 3));
		s->y_start -= (s->y_start - y) / (s->zoom / (s->zoom / 3));
		s->zoom -= s->zoom / 3;
	}
	s->zoom = (s->zoom <= 1) ? 1 : s->zoom;
	return (0);
}

int				ptr_motion_hook(int x, int y, t_mlx *s)
{
	if (s->f_lock > 0)
	{
		if (x >= 0 && y >= 0 && x <= WIN_MAX_X && y <= WIN_MAX_Y)
		{
		}
	}
//	expose_hook(s);
	return (0);
}

void			key_zoom_handler(int key, t_mlx *s)
{
	s->zoom = (s->zoom <= 50) ? 50 : s->zoom;
	if (key == 69)
	{
		s->cam.c.x -= 0.25f;
	}
	else if (key == 78)
	{
		s->cam.c.x += 0.25f;
	}
	s->zoom = (s->zoom <= 1) ? 1 : s->zoom;
}

int				key_win_handler(int key, t_mlx *s)
{
	key_zoom_handler(key, s);
	if (key == 53)
		exit(0);
	else if (key == 67)
		s->max_ite += 1000;
	else if (key == 75 && s->max_ite > 10)
		s->max_ite -= 1000;
	else if (key == 123)
		s->cam.c.z -= 0.25f;
	else if (key == 124)
		s->cam.c.z += 0.25f;
	else if (key == 126)
		s->cam.c.y -= 0.25f;
	else if (key == 125)
		s->cam.c.y += 0.25f;
	return (0);
}
