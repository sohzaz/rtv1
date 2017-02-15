/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:59:13 by dbreton           #+#    #+#             */
/*   Updated: 2017/02/15 14:44:19 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_color			plane_diffuse(t_object *src, t_object *self,
		t_vector *inter)
{
	t_vector			light_v;
	double				l_dot_normal;
	t_color				tmp;

	light_v.x = src->x - inter->x;
	light_v.y = src->y - inter->y;
	light_v.z = src->z - inter->z;
	normalize_vector(&light_v);
	l_dot_normal = fabs(dot(&self->dir, &light_v));
	tmp = mult_color_double(mult_color_double(
				mult_color(src->color, self->color),
				(self->kd * l_dot_normal)), src->intensity);
	return (tmp);
}

t_color					plane_specular(t_object *src, t_object *self,
		t_vector *inter, t_vector *v)
{
	t_vector			vecs[4];
	double				l_dot_normal;
	t_color				tmp;

	vecs[1] = self->dir;
	vecs[0].x = src->x - inter->x;
	vecs[0].y = src->y - inter->y;
	vecs[0].z = src->z - inter->z;
	normalize_vector(&vecs[0]);
	vecs[3] = sub_vec_by_vec(*inter, *v);
	normalize_vector(&vecs[3]);
	l_dot_normal = dot(&vecs[1], &vecs[0]);
	if (l_dot_normal > 0.0f)
	{
		vecs[2] = sub_vec_by_vec(
			mult_vec_double(vecs[1], 2.0f * dot(&vecs[0], &vecs[1])), vecs[0]);
		tmp = mult_color_double(
				src->color, pow(dot(&vecs[2], &vecs[3]),
					self->psh) * src->intensity);
	}
	else
		tmp = create_color("0,0,0");
	return (tmp);
}

static double			*plane_inter(t_object self, t_vector *v, t_vector org)
{
	double				v_dot;
	double				*res;
	t_vector			v0;

	v_dot = dot(v, &self.dir);
	v0.x = org.x - self.x;
	v0.y = org.y - self.y;
	v0.z = org.z - self.z;
	res = (double *)malloc(sizeof(double) * 3);
	if (v_dot != 0.0f)
	{
		res[0] = 1.0f;
		res[1] = -1.0f * dot(&v0, &self.dir) / v_dot;
	}
	else
		res[0] = -1.0f;
	return (res);
}

t_object				plane(char **tmp)
{
	t_object			pl;

	pl.inter = &plane_inter;
	pl.diffuse = &plane_diffuse;
	pl.specular = &plane_specular;
	pl.id = ft_atoi(tmp[0]);
	pl.x = ft_atoi(tmp[2]);
	pl.y = ft_atoi(tmp[3]);
	pl.z = ft_atoi(tmp[4]);
	pl.dir.x = ft_atoi(tmp[5]);
	pl.dir.y = ft_atoi(tmp[6]);
	pl.dir.z = ft_atoi(tmp[7]);
	pl.kd = ft_atoi(tmp[10]) / 100.0f;
	normalize_vector(&pl.dir);
	pl.color = create_color(tmp[1]);
	pl.ks = ft_atoi(tmp[11]) / 100.0f;
	pl.psh = ft_atoi(tmp[12]);
	return (pl);
}
