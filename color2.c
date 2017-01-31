/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:47:20 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 16:47:29 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
int 			is_below_threshold(t_color c, float thresh)
{
	if ((c.r < thresh) && (c.g < thresh) && (c.b < thresh))
		return (1);
	else
		return (0);
}

int				get_color_value(t_color c)
{
	int			res;

	res = (unsigned char)(c.r * 255) & 0xFF;
	res += ((unsigned char)(c.g * 255) & 0x00FF) << 8;
	res += ((unsigned char)(c.b * 255) & 0x0000FF) << 16;
	return (res);
}
