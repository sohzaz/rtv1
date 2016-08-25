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

static int			sphere_inter(t_object *objs, t_vector *v, t_camera cam) {
	//Pvector = (cam.x + t.v->x, cam.y + t.v->y, cam.z + t.v->z)
	(void)objs;
	(void)cam;
	(void)v;
	printf("sphere\n");
	//printf("%f||%f||%f\n", v->x, v->y, v->z)
	return (0);
}

t_object			sphere(char **tmp) {
	t_object		sp;

	sp.inter = &sphere_inter;
	(void)tmp;
	return (sp);	
}
