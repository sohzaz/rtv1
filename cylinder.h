//
// Created by Drien BRETON on 1/4/17.
//

#ifndef RTV1_CYLINDER_H
# define RTV1_CYLINDER_H
# include "fractol.h"
# include "sphere.h"

t_color 			get_cyl_diffuse(t_object *src, t_object *self,
								   t_vector *inter);
t_vector			cyl_normal(t_vector *inter, t_object *self);



#endif
