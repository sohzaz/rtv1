#ifndef SPHERE_H
# define SPHERE_H
# include "fractol.h"

int 				in_shadow(t_object *obj, t_object *v,
					 t_vector *inter);
t_vector			sphere_normal(t_vector *intersect, t_object *self);
double 				get_sphere_diffuse(t_object *src, t_object *self,
									 t_vector *inter);

#endif
