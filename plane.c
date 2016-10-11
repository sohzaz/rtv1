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

static double			*plane_inter(t_object *objs, t_vector *v, t_camera cam, t_object self) {
    //Pvector = (cam.x + t.v->x, cam.y + t.v->y, cam.z + t.v->z)
    (void)objs;
    (void)cam;
    (void)v;
    (void)self;

    //return closest point distance
    return (0);
}

t_object			plane(char **tmp) {
    t_object		pl;


    pl.inter = &plane_inter;
    pl.id = ft_atoi(tmp[0]);
    pl.x = ft_atoi(tmp[2]);
    pl.y = ft_atoi(tmp[3]);
    pl.z = ft_atoi(tmp[4]);
    pl.rot_x = ft_atoi(tmp[5]);
    pl.rot_y = ft_atoi(tmp[6]);
    pl.rot_z = ft_atoi(tmp[7]);
    return (pl);
}


