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
static double           *calc_result(double a, double b, double d) {
    double *res;

    res = (double *)malloc(sizeof(double) * 3);
    res[0] = -1.0f;
    if (d == 0)
    {
        res[0] = 1.0f;
        res[1] = (-1 * b) / (2 * a);
    }
    else if (d > 0)
    {
        res[0] = 2.0f;
        res[1] = ((-1 * b) - sqrt(d)) / (2 * a);
        res[2] = ((-1 * b) + sqrt(d)) / (2 * a);

    }
    printf("out:%f||%f||%f\n", res[0], res[1], res[2]);
    return(res);
}

static double			*sphere_inter(t_object *objs, t_vector *v, t_camera cam, t_object self) {
	//Pvector = (cam.x + t.v->x, cam.y + t.v->y, cam.z + t.v->z)
    double a;
    double b;
    double c;
    double d;

    a = pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2);
    b = 2 * (v->x * (cam.c.x - self.x) + v->y * (cam.c.y - self.y) + v->z * (cam.c.z - self.z));
    c = (pow(cam.c.x - self.x, 2) + pow(cam.c.y - self.y, 2) + pow(cam.c.z - self.z, 2)) - pow(self.radius, 2);
    d = b * b - 4 * (a * c);

    printf("in:%f||%f||%f\n", a, b, c);

	(void)objs;
    return (calc_result(a, b, d));
}

t_object			sphere(char **tmp) {
	t_object		sp;

	sp.inter = &sphere_inter;
    sp.id = ft_atoi(tmp[0]);
    sp.x = ft_atoi(tmp[2]);
    sp.y = ft_atoi(tmp[3]);
    sp.z = ft_atoi(tmp[4]);
    sp.rot_x = ft_atoi(tmp[5]);
    sp.rot_y = ft_atoi(tmp[6]);
    sp.rot_z = ft_atoi(tmp[7]);
    sp.radius = ft_atoi(tmp[8]);
	return (sp);
}
