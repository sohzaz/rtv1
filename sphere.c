/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:56:03 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/20 16:50:56 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "sphere.h"

static double           *calc_result(double a, double b, double d)
{
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
    return(res);
}

t_vector			sphere_normal(t_vector *intersect, t_object *self)
{
	t_vector			res;
	t_vector			center;

	center.x = self->x;
	center.y = self->y;
	center.z = self->z;
	res = sub_vec_by_vec(*intersect, center);
	normalize_vector(&res);
	return (res);
}

t_color 			sphere_diffuse(t_object *src, t_object *self,
									  t_vector *inter)
{
	t_vector	light_v;
	t_vector	surface_normal;
	double 		l_dot_normal;
	t_color		tmp;

	light_v.x = src->x - inter->x;
	light_v.y = src->y - inter->y;
	light_v.z = src->z - inter->z;
	light_v.length = sqrt(light_v.x * light_v.x + light_v.y * light_v.y
						  + light_v.z * light_v.z);
	normalize_vector(&light_v);
	surface_normal = sphere_normal(inter, self);
	l_dot_normal = dot(&surface_normal, &light_v);
	//printf("l_dot_normal: %f\n", l_dot_normal);
	l_dot_normal *= l_dot_normal > 0.0f;
	//printf("l_dot_normal_a: %f\n", l_dot_normal);
	tmp = mult_color_double(mult_color_double(
			mult_color(src->color, self->color),
			((self->kd) * l_dot_normal)), src->intensity);
	//printf("sphere diffuse color: {%f, %f, %f}\n", inter->x, inter->y, inter->z);
	return (tmp);
}

static double			*sphere_inter(t_object self, t_vector *v,
									   t_vector org)
{
    double a;
    double b;
    double c;
    double d;

	a = dot(v, v);
    b = 2 * (v->x * (org.x - self.x) + v->y * (org.y - self.y) + v->z * (org.z - self.z));
    c = (pow(org.x - self.x, 2) + pow(org.y - self.y, 2) + pow(org.z - self.z, 2)) - pow(self.radius, 2);
    d = b * b - 4 * (a * c);
    return (calc_result(a, b, d));
}

t_object			sphere(char **tmp)
{
	t_object		sp;
	sp.normal = &sphere_normal;
	sp.inter = &sphere_inter;
	sp.diffuse = &sphere_diffuse;
    sp.id = ft_atoi(tmp[0]);
    sp.x = ft_atoi(tmp[2]);
    sp.y = ft_atoi(tmp[3]);
    sp.z = ft_atoi(tmp[4]);
    sp.rot_x = ft_atoi(tmp[5]);
    sp.rot_y = ft_atoi(tmp[6]);
    sp.rot_z = ft_atoi(tmp[7]);
    sp.radius = ft_atoi(tmp[8]);
	sp.color = create_color(tmp[1]);
	sp.kd = ft_atoi(tmp[10]) / 100.0f;
	/*printf("sphere:{id:%d,\nx:%d,\ny:%d,\nz:%d,\nradius:%d,\ncolor:%d\n}", sp.id,
	sp.x,
	sp.y,
	sp.z, sp.radius,
	sp.color);*/
	return (sp);
}
