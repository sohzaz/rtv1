//
// Created by Drien BRETON on 1/10/17.
//

#include "cone.h"

t_color	get_cone_ambiant(t_object *src, t_object *self,
							  t_vector *inter)
{
	(void)inter;
	t_vector light_v;
	light_v.x = inter->x - inter->x;
	light_v.y = inter->y - inter->y;
	light_v.z = inter->z - inter->z;
	light_v.length = sqrt(pow(light_v.x, 2) +
						  pow(light_v.y, 2) +
						  pow(light_v.z, 2));
	t_color test;
	test.r = 1.0f;
	test.g = 1.0f;
	test.b = 1.0f;
	(void)self;
	(void)src;

	(void)light_v;
	return (test);
	/*return(mult_color_double(
			mult_color(src->color, self->color),
			(self->kd * 0.1) * 0.1));*/
}

t_color 			get_cone_diffuse(t_object *src, t_object *self,
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
	tmp = mult_color_double(mult_color_double(
			mult_color(src->color, self->color),
			((self->kd) * l_dot_normal)), src->intensity);
	//printf("sphere diffuse color: {%f, %f, %f}\n", inter->x, inter->y, inter->z);
	return (tmp);
}