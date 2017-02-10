/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:06:10 by dbreton           #+#    #+#             */
/*   Updated: 2017/02/02 17:08:29 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char			validate_direction(t_vector *io,
										t_vector *norm,
										t_object *self, t_vector *piv)
{
	double			est_tan;
	double			exp_tan;

	est_tan = norm->length / io->length;
	exp_tan = tan(self->radius);
	if (!almost_equal_relative(est_tan, exp_tan))
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
t_color			cone_specular(t_object *src, t_object *self,
								   t_vector *inter, t_vector *v)
{
	t_vector			vecs[4];
	double				l_dot_normal;
	t_color				tmp;

	vecs[1] = self->normal(inter, self);
	vecs[0].x = src->x - inter->x;
	vecs[0].y = src->y - inter->y;
	vecs[0].z = src->z - inter->z;
	normalize_vector(&vecs[0]);
	vecs[3] = sub_vec_by_vec(*inter, *v);
	normalize_vector(&vecs[3]);
	l_dot_normal = dot(&vecs[1], &vecs[0]);
	if (l_dot_normal > 0.0f)
	{
		vecs[2] = sub_vec_by_vec(mult_vec_double(vecs[1], 2.0f * dot(&vecs[0], &vecs[1])),vecs[0]);
		tmp = mult_color_double(src->color, pow(dot(&vecs[2], &vecs[3]), self->psh));
	}
	else
		tmp = create_color("0,0,0");
	return (tmp);
}
