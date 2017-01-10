//
// Created by Drien BRETON on 1/10/17.
//

#ifndef RTV1_CONE_H
# define RTV1_CONE_H
# include "fractol.h"
# include "sphere.h"

t_vector			cone_normal(t_vector *intersect, t_object *self);
t_color	get_cone_ambiant(t_object *src, t_object *self,
							t_vector *inter);
t_color 			get_cone_diffuse(t_object *src, t_object *self,
									t_vector *inter);

#endif
