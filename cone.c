/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:48:11 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/20 16:48:15 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

static double 		*calc_res(double *params)
{
	double 			*res;

	res = (double *)malloc(sizeof(double) * 3);
	res[0] = -1.0f;
	if (params[3] == 0.0)
	{
		res[0] = 1.0f;
		res[1] = (-1 * params[1]) / (2 * params[0]);
	}
	else if (params[3] > 0.0)
	{
		res[0] = 2.0f;
		res[1] = ((-1 * params[1]) - sqrt(params[3])) / (2 * params[0]);
		res[2] = ((-1 * params[1]) + sqrt(params[3])) / (2 * params[0]);
	}
	return(res);
}

t_vector			cone_normal(t_vector *inter, t_object *self)
{
	t_vector		io;
	t_vector		piv;
	t_vector		pi;
	t_vector		norm;

	io.x = inter->x - self->x;
	io.y = inter->y - self->y;
	io.z = inter->z - self->z;
	piv = mult_vec_double(self->dir, (dot(&io, &self->dir)
									  / dot(&self->dir, &self->dir)));
	pi.x = self->x + piv.x;
	pi.y = self->y + piv.y;
	pi.z = self->z + piv.z;
	norm = sub_vec_by_vec(*inter, pi);
	norm = sub_vec_by_vec(norm, mult_vec_by_vec(piv,mult_vec_double(self->dir, pow(tan(self->radius), 2))));


	normalize_vector(&norm);
	return (norm);
}

static double 		*cone_inter(t_object self, t_vector *v,
								t_vector org)
{
	double			params[4];
	t_vector		ao;

	ao.x = org.x - self.x;
	ao.y = org.y - self.y;
	ao.z = org.z - self.z;
	params[0] = dot(v, v) - (1.0f + pow(tan(self.radius), 2))
							  * pow(dot(v, &self.dir), 2);
	params[1] = 2.0f * (dot(v, &ao) - (1.0f + pow(tan(self.radius), 2))
									  * dot(v, &self.dir) * dot(&ao, &self.dir));
	params[2] = dot(&ao, &ao) - (1.0f + pow(tan(self.radius), 2))
								* pow(dot(&ao, &self.dir), 2);
	params[3] = params[1] * params[1] - 4*params[0] * params[2];
	return (calc_res(params));
}

t_color 			cone_diffuse(t_object *src, t_object *self,
									t_vector *inter)
{
	t_vector	light_v;
	t_vector	surface_normal;
	double 		l_dot_normal;
	t_color		tmp;

	light_v.x = src->x - inter->x;
	light_v.y = src->y - inter->y;
	light_v.z = src->z - inter->z;
	light_v.length = sqrt(light_v.x * light_v.x + light_v.y * light_v.y
						  + light_v.z * light_v.z);
	normalize_vector(&light_v);
	surface_normal = cone_normal(inter, self);
	l_dot_normal = dot(&surface_normal, &light_v);
	//printf("l_dot_normal: %f\n", l_dot_normal);
	l_dot_normal *= l_dot_normal > 0.0f;
	//printf("l_dot_normal_a: %f\n", l_dot_normal);
	tmp = mult_color_double(mult_color_double(
			mult_color(src->color, self->color),
			((self->kd) * l_dot_normal)), src->intensity);
	//printf("sphere diffuse color: {%f, %f, %f}\n", inter->x, inter->y, inter->z);
	return (tmp);
}

t_object			cone(char **tmp)
{
	t_object		sp;
	//sp.normal = &sphere_normal;
	sp.inter = &cone_inter;
	sp.diffuse = &cone_diffuse;
	sp.id = ft_atoi(tmp[0]);
	sp.x = ft_atoi(tmp[2]);
	sp.y = ft_atoi(tmp[3]);
	sp.z = ft_atoi(tmp[4]);
	sp.dir.x = ft_atoi(tmp[5]);
	sp.dir.y = ft_atoi(tmp[6]);
	sp.dir.z = ft_atoi(tmp[7]);
	sp.radius = (ft_atoi(tmp[8]) * M_PI) / 180;
	sp.color = create_color(tmp[1]);
	sp.kd = ft_atoi(tmp[10]) / 100.0f;
	normalize_vector(&sp.dir);
	return (sp);
}

