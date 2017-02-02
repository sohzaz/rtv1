//
// Created by Drien BRETON on 2/2/17.
//
#include "fractol.h"

static char			validate_direction(t_vector *io,
										  t_vector *norm,
										  t_object *self, t_vector *piv)
{
	double 			est_tan;
	double 			exp_tan;


	est_tan = norm->length / io->length;
	exp_tan = tan(self->radius);
	if(!almost_equal_relative(est_tan, exp_tan))
	{
		*piv = mult_vec_double(self->dir,
							-1.0f * io->length / cos(self->radius));
		piv->x += self->x;
		piv->y += self->y;
		piv->z += self->z;
		return (0);
	}
	return (1);
}

t_vector			cone_normal(t_vector *inter, t_object *self)
{
	t_vector		io;
	t_vector		piv;
	double			pi;
	t_vector		norm;

	io.x = inter->x - self->x;
	io.y = inter->y - self->y;
	io.z = inter->z - self->z;
	comp_vector_length(&io);
	pi = io.length / cos(self->radius);
	piv = mult_vec_double(self->dir, pi);
	piv.x += self->x;
	piv.y += self->y;
	piv.z += self->z;
	norm = sub_vec_by_vec(*inter, piv);
	comp_vector_length(&norm);
	if (!validate_direction(&io, &norm, self, &piv))
		norm = sub_vec_by_vec(*inter, piv);
	normalize_vector(&norm);
	return (norm);
}