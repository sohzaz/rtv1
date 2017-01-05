//
// Created by Drien BRETON on 1/4/17.
//
#include "cylinder.h"
t_vector			cyl_normal(t_vector *inter, t_object *self)
{
	t_vector		io;
	t_vector		piv;
	t_vector		pi;
	t_vector		norm;

	io.x = inter->x - self->x;
	io.y = inter->y - self->y;
	io.z = inter->z - self->z;
	piv = mult_vec_double(self->dir, (dot(&io, &self->dir)
									  / dot(&self->dir, &self->dir)));
	pi.x = self->x + piv.x;
	pi.y = self->y + piv.y;
	pi.z = self->z + piv.z;
	norm = sub_vec_by_vec(*inter, pi);
	printf("in:{%f, %f, %f}\nres:{%f, %f, %f}\n", inter->x, inter->y, inter->z, norm.x, norm.y, norm.z);
	return (sub_vec_by_vec(*inter, pi));
}

t_color 			get_cyl_diffuse(t_object *src, t_object *self,
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
	surface_normal = cyl_normal(inter, self);
	l_dot_normal = dot(&surface_normal, &light_v);
	//printf("l_dot_normal: %f\n", l_dot_normal);
	l_dot_normal *= l_dot_normal > 0.0f;
	//printf("l_dot_normal_a: %f\n", l_dot_normal);
	tmp = mult_color_double(
			mult_color(src->color, self->color),
			((self->kd / 100) * l_dot_normal) /*/
			pow(light_v.length, 2)*/);
	return (tmp);
}
