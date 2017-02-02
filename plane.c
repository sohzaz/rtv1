/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:59:13 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:48:27 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "sphere.h"

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
			(self->kd * l_dot_normal)), src->intensity /
			(log(light_v.length)));
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
	if (v_dot > 0.0f)
	{
		res[0] = 1.0f;
		res[1] = -1.0f * dot(&v0, &self.dir) / v_dot;
		res[1] *= (res[1] < 0.0f) ? -1.0f : 1.0f;
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
	return (pl);
}
