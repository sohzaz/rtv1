/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:24:03 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 14:24:13 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static double		*calc_res(double *params)
{
	double			*res;

	res = (double *)malloc(sizeof(double) * 3);
	res[0] = -1.0f;
	if (params[3] == 0)
	{
		res[0] = 1.0f;
		res[1] = (-1 * params[1]) / (2 * params[0]);
	}
	else if (params[3] > 0)
	{
		res[0] = 2.0f;
		res[1] = ((-1 * params[1]) - sqrt(params[3])) / (2 * params[0]);
		res[2] = ((-1 * params[1]) + sqrt(params[3])) / (2 * params[0]);
	}
	return (res);
}

t_vector			cyl_normal(t_vector *inter, t_object *self)
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
	normalize_vector(&norm);
	return (norm);
}

static double		*cyl_inter(t_object self, t_vector *v,
								t_vector org)
{
	double			params[4];
	double			ab;
	t_vector		aob;
	t_vector		vab;
	t_vector		ao;

	ao.x = org.x - self.x;
	ao.y = org.y - self.y;
	ao.z = org.z - self.z;
	aob = mult_vec_by_vec(ao, self.dir);
	vab = mult_vec_by_vec(*v, self.dir);
	ab = dot(&self.dir, &self.dir);
	params[0] = dot(&vab, &vab);
	params[1] = 2 * dot(&vab, &aob);
	params[2] = dot(&aob, &aob) - (self.radius * self.radius * ab);
	params[3] = params[1] * params[1] - (4 * params[0] * params[2]);
	return (calc_res(params));
}

t_color				cyl_diffuse(t_object *src, t_object *self,
								t_vector *inter)
{
	t_vector		light_v;
	t_vector		surface_normal;
	double			l_dot_normal;
	t_color			tmp;

	light_v.x = src->x - inter->x;
	light_v.y = src->y - inter->y;
	light_v.z = src->z - inter->z;
	light_v.length = sqrt(light_v.x * light_v.x + light_v.y * light_v.y
						+ light_v.z * light_v.z);
	normalize_vector(&light_v);
	surface_normal = cyl_normal(inter, self);
	l_dot_normal = dot(&surface_normal, &light_v);
	l_dot_normal = (l_dot_normal > 0.0f) ? l_dot_normal : 0.0f;
	tmp = mult_color_double(mult_color_double(
			mult_color(src->color, self->color),
			(self->kd * l_dot_normal)), src->intensity);
	return (tmp);
}

t_object			cylinder(char **tmp)
{
	t_object		sp;

	sp.inter = &cyl_inter;
	sp.diffuse = &cyl_diffuse;
	sp.normal = &cyl_normal;
	sp.specular = &cyl_specular;
	sp.id = ft_atoi(tmp[0]);
	sp.x = ft_atoi(tmp[2]);
	sp.y = ft_atoi(tmp[3]);
	sp.z = ft_atoi(tmp[4]);
	sp.dir.x = ft_atoi(tmp[5]);
	sp.dir.y = ft_atoi(tmp[6]);
	sp.dir.z = ft_atoi(tmp[7]);
	sp.radius = ft_atoi(tmp[8]);
	sp.color = create_color(tmp[1]);
	sp.kd = ft_atoi(tmp[10]) / 100.0f;
	sp.kd *= (sp.kd >= 0.0f);
	sp.ks = ft_atoi(tmp[11]) / 100.0f;
	sp.ks *= (sp.ks >= 0.0f);
	sp.psh = ft_atoi(tmp[12]);
	sp.psh *= (sp.psh >= 0.0f);
	normalize_vector(&sp.dir);
	return (sp);
}
