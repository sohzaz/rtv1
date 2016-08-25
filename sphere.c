/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:56:03 by dbreton           #+#    #+#             */
/*   Updated: 2016/05/23 14:02:22 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int			inter(t_object *objs, t_vector *v, t_camera cam) {
	(void)objs;
	(void)cam;
	printf("%f\n", v->x);
	if (v->x >= 2.0 && v->x <= 9.0 && v->y >= 2.0 && v->y <=9.0)
		return (0x503467);
	else
		return (0);
}

t_object			sphere(char **tmp) {
	t_object		sp;

	sp.inter = &inter;
	(void)tmp;
	return (sp);	
}
