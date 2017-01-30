/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:15:12 by dbreton           #+#    #+#             */
/*   Updated: 2015/10/26 13:12:40 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_in_image(t_mlx *s, int x, int y, t_color color)
{
	SDL_PixelFormat pixelFormat;

	pixelFormat.format = s->format;
	if ((x < s->wh[0] -1) && y < (s->wh[1] - 1))
	{
		Uint32 pixelPosition = y * (s->pitch / sizeof(unsigned int)) + x;
		s->pixels[pixelPosition] = get_color_value(color);
		//s->pixels[pixelPosition] = SDL_MapRGBA(&s->pixelFormat, (color.r * 255),
		//		   (color.g * 255), (color.b * 255), 0);
	}
}

void				ft_exit(const int code, const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(code);
}
