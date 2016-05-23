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

void				put_in_image(t_mlx *s, int x, int y, int color)
{
	char			*start;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	new_color;

	start = mlx_get_data_addr(s->img, &bpp, &size_line, &endian);
	new_color = mlx_get_color_value(s->mlx, color);
	if (x < (WIN_MAX_X) && y < (WIN_MAX_Y)
			&& x > 0 && y > 0)
	{
		start[(x * (bpp / 8)) + (y * size_line)] = new_color & 0xFF;
		start[(x * (bpp / 8)) + (y * size_line) + 1] = (new_color
				& 0xFF00) >> 8;
		start[(x * (bpp / 8)) + (y * size_line) + 2] = (new_color
				& 0xFFFF00) >> 16;
	}
}
