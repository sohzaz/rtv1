/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:59:13 by dbreton           #+#    #+#             */
/*   Updated: 2016/08/25 15:59:21 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int			plane_inter(t_object *objs, t_vector *v, t_camera cam) {
    //Pvector = (cam.x + t.v->x, cam.y + t.v->y, cam.z + t.v->z)
    (void)objs;
    (void)cam;
    (void)v;
    printf("plane\n");

    return (0);
}

t_object			plane(char **tmp) {
    t_object		pl;

    pl.inter = &plane_inter;
    (void)tmp;
    return (pl);
}

