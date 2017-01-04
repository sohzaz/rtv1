//
// Created by Drien BRETON on 1/4/17.
//
#include "cylinder.h"
t_vector			cyl_normal(t_vector *inter, t_object *self)
{
	t_vector		norm;

	(void)inter;

	norm.x = self->dir.x;
	norm.y = self->dir.y;
	norm.z = 0.0f;
	//norm = self->dir;
	return (norm);
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
