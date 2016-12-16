/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:54:57 by dbreton           #+#    #+#             */
/*   Updated: 2016/11/29 10:54:59 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_object		source(char **tmp)
{
	t_object	src;

	src.x = ft_atoi(tmp[1]);
	src.y = ft_atoi(tmp[2]);
	src.z = ft_atoi(tmp[3]);
	src.color = create_color(tmp[4]);
	return (src);
}


