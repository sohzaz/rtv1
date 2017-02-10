/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:08:58 by dbreton           #+#    #+#             */
/*   Updated: 2017/02/02 17:09:04 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

static double		*calc_res(double *params)
{
	double			*res;

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
	return (res);
}

static double		*cone_inter(t_object self, t_vector *v,
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
	params[3] = params[1] * params[1] - 4 * params[0] * params[2];
	return (calc_res(params));
}

t_color				cone_diffuse(t_object *src, t_object *self,
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
	surface_normal = cone_normal(inter, self);
	l_dot_normal = dot(&surface_normal, &light_v);
	l_dot_normal *= l_dot_normal > 0.0f;
	tmp = mult_color_double(mult_color_double(
			mult_color(src->color, self->color),
			(self->kd * l_dot_normal)), src->intensity);
	return (tmp);
}

t_object			cone(char **tmp)
{
	t_object		sp;

	sp.inter = &cone_inter;
	sp.diffuse = &cone_diffuse;
	sp.normal = &cone_normal;
	sp.specular = &cone_specular;
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
	sp.ks = ft_atoi(tmp[11]) / 100.0f;
	sp.psh = ft_atoi(tmp[12]);
	normalize_vector(&sp.dir);
	return (sp);
}
