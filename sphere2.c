/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:27:14 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:27:40 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

/*int				in_shadow(t_object *obj, t_object *v,
					t_vector *inter)
{
	int			res;
	double		*inter_res;
	double		i;
	t_vector	light_v;

	res = 0;
	i = 1.0f;
	light_v.x = v->x - inter->x;
	light_v.y = v->y - inter->y;
	light_v.z = v->z - inter->z;
	light_v.length = sqrt(pow(light_v.x, 2) + pow(light_v.y, 2)
						+ pow(light_v.z, 2));
	normalize_vector(&light_v);
	inter_res = obj->inter(*obj, &light_v, *inter);
	while (i < inter_res[0])
	{
		if (inter_res[(int)i] > 0.0f && inter_res[(int)i] < light_v.length)
		{
			res = 1;
			break ;
		}
		++i;
	}
	free(inter_res);
	return (res);
}*/
t_color			sphere_specular(t_object *src, t_object *self,
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
