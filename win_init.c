/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 19:15:07 by dbreton           #+#    #+#             */
/*   Updated: 2017/02/15 14:57:29 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		texture_refresh(t_mlx *s)
{
	if (s->need_refresh)
	{
		SDL_QueryTexture(s->img, &s->format, NULL, &s->wh[0], &s->wh[1]);
		SDL_LockTexture(s->img, NULL, (void**)&s->pixels, &s->pitch);
		render_pic(s);
		ft_putstr("Scene rendered\n");
		s->need_refresh = 0;
		SDL_UnlockTexture(s->img);
		s->need_reload = 1;
	}
}

static void		render(t_mlx *s)
{
	if (s->need_reload)
	{
		SDL_RenderClear(s->ren);
		SDL_RenderCopy(s->ren, s->img, NULL, NULL);
		SDL_RenderPresent(s->ren);
		s->need_reload = 0;
	}
}

void			expose_hook(t_mlx *s)
{
	SDL_Event	ev;

	while (1)
	{
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
			{
				SDL_Quit();
				exit(0);
			}
		}
		texture_refresh(s);
		render(s);
	}
}

void			win_init(t_mlx s)
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
							SDL_TEXTUREACCESS_STREAMING,
							WIN_MAX_X + 1, WIN_MAX_Y + 1);
	if (s.win && s.img && s.ren)
	{
		s.need_refresh = 1;
		expose_hook(&s);
	}
	else
		ft_exit(3, "renderer init failed");
}
