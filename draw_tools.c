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

#include "rtv1.h"

void				put_in_image(t_mlx *s, int x, int y, t_color color)
{
	unsigned int	pixel_position;
	static pthread_mutex_t	mutex;

	pthread_mutex_lock(&mutex);
	if ((x < s->wh[0]) && y < (s->wh[1]))
	{
		pixel_position = y * (s->pitch / sizeof(unsigned int)) + x;
		s->pixels[pixel_position] = get_color_value(color);
	}
	pthread_mutex_unlock(&mutex);
}

void				ft_exit(const int code, const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(code);
}
