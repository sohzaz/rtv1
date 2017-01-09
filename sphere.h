#ifndef SPHERE_H
# define SPHERE_H
# include "fractol.h"


t_vector			sphere_normal(t_vector *intersect, t_object *self);
t_color 				get_sphere_diffuse(t_object *src, t_object *self,
								 t_vector *inter);
t_color 				get_sphere_ambiant(t_object *src, t_object *self,
							 t_vector *inter);
void				comp_curr_diff(t_color* diffuse, int shadow,
								   t_color new_diff);
double 				sphere_color(t_mlx *s, t_object *self, t_vector inter);

#endif
