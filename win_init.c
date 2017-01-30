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


int expose_hook(t_mlx *s)
{
	while (1)
	{
		//SDL_RenderClear(s->ren);
		if (s->need_refresh)
		{
			SDL_QueryTexture(s->img, &s->format, NULL, &s->wh[0], &s->wh[1]);
			SDL_LockTexture(s->img, NULL, (void**)&s->pixels, &s->pitch);
			write(1, "B", 1);
			render_pic(s);
			s->need_refresh = 0;
			SDL_UnlockTexture(s->img);
		}
		SDL_RenderCopy(s->ren, s->img, NULL, NULL);
		SDL_RenderPresent(s->ren);
	}
	return (0);
}

void win_init(t_mlx s)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_exit(3, "sdl init failed");
	s.win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
							 SDL_WINDOWPOS_UNDEFINED,
							 WIN_MAX_X,
							 WIN_MAX_Y,
							 SDL_WINDOW_SHOWN);
	s.ren = SDL_CreateRenderer(s.win, -1, SDL_RENDERER_ACCELERATED);
	s.img = SDL_CreateTexture(s.ren, SDL_PIXELFORMAT_RGBA32,
							  SDL_TEXTUREACCESS_STREAMING, WIN_MAX_X, WIN_MAX_Y);
	if (s.win && s.img && s.ren)
	{
		write(1,"A", 1);
		s.need_refresh = 1;
		expose_hook(&s);
	}
	else
	{exit(1);}
}
