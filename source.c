/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:54:57 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/20 16:50:40 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object		source(char **tmp)
{
	t_object	src;

	src.x = ft_atoi(tmp[1]);
	src.y = ft_atoi(tmp[2]);
	src.z = ft_atoi(tmp[3]);
	src.color = create_color(tmp[4]);
	src.intensity = ft_atoi(tmp[5]) / 100.0f;
	return (src);
}
