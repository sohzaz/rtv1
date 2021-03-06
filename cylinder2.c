/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:45:38 by dbreton           #+#    #+#             */
/*   Updated: 2017/02/15 14:46:33 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color			cyl_specular(t_object *src, t_object *self,
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
	vecs[3] = sub_vec_by_vec(*v, *inter);
	normalize_vector(&vecs[3]);
	l_dot_normal = dot(&vecs[1], &vecs[0]);
	if (l_dot_normal > 0.0f)
	{
		vecs[2] = sub_vec_by_vec(
			mult_vec_double(vecs[1], 2.0f * dot(&vecs[0], &vecs[1])), vecs[0]);
		tmp = mult_color_double(
			src->color, pow((dot(&vecs[2], &vecs[3]) > 0) ? dot(&vecs[2],
				&vecs[3]) : 0, self->psh) * src->intensity * self->ks);
	}
	else
		tmp = create_color("0,0,0");
	return (tmp);
}
