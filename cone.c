//
// Created by Drien BRETON on 1/10/17.
//

#include "cone.h"

static double 		*calc_res(double *params)
{
	double 			*res;

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
	return(res);
}
//TODO Implement m calc
static t_matrix		calc_m(t_object self)
{
	t_matrix		m;

	m = new_matrix(3, 3);
	m.cont[0][0] = pow(self.dir.x, 2) - (pow(
			cos(self.radius * M_PI / 180.0), 2));
	m.cont[0][1] = self.dir.x * self.dir.y;
	m.cont[0][2] = self.dir.x * self.dir.z;
	m.cont[1][0] = self.dir.x * self.dir.y;
	m.cont[1][1] = pow(self.dir.y, 2) - (pow(
			cos(self.radius * M_PI / 180.0), 2));
	m.cont[1][2] = self.dir.y * self.dir.z;
	m.cont[2][0] = self.dir.x * self.dir.z;
	m.cont[2][1] = self.dir.y * self.dir.z;
	m.cont[2][2] = pow(self.dir.z, 2) - (pow(
			cos(self.radius * M_PI / 180.0), 2));
	return(m);
}
static double 		*cone_inter(t_object self, t_vector *v,
								t_vector org)
{
	double			params[4];
	t_matrix		m;
	t_vector		ao;

	ao.x = org.x - self.x ;
	ao.y = org.y - self.y ;
	ao.z = org.z - self.z ;
	m = calc_m(self);
	params[0] = syme_product(v, &m, v);
	params[1] = syme_product(v, &m, &ao);
	params[2] = syme_product(&ao, &m, &ao);
	params[3] = params[1] * params[1] - (4 * params[0] * params[2]);
//	printf("params:\n[0]%f\n[1]%f\n[2]%f\n[3]%f\nab:%f\nv:{\n\tx:%f,\n\ty:%f,\n\tz:%f\n}\n", params[0], params[1], params[2],params[3], ab, v->x, v->y, v->z);
	return (calc_res(params));
}
double 				cone_color(t_mlx *s, t_object *self, t_vector inter)
{
	int 			i;
	int 			j;
	int 			shadow;
	t_color			diffuse;
	//t_color			ambiant;
	/*int 			phong;*/

	i = 0;
	diffuse.r = NAN;
	while (i < s->src_len)
	{
		j = 0;
		while (j < s->obj_len)
		{
			shadow = !(in_shadow(&s->objects[j], &s->sources[i], &inter));
			comp_curr_diff(&diffuse, shadow,
						   get_cone_diffuse(&s->sources[i], self, &inter));
			/*	ambiant = (ambiant.r) ? get_sphere_ambiant(&s->sources[i],
														 self, &inter) :
						add_color(ambiant, get_sphere_ambiant(&s->sources[i],
															  self, &inter));*/
			//printf("shadow:%d\n\n", shadow);
			++j;
		}
		++i;
	}
	//	return (get_color_value(add_color(diffuse, ambiant)));
	return (get_color_value(diffuse));
}

t_object			cone(char **tmp)
{
	t_object		sp;
	//sp.normal = &sphere_normal;
	sp.inter = &cone_inter;
	sp.get_color = &cone_color;
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
	normalize_vector(&sp.dir);
	/*printf("sphere:{id:%d,\nx:%d,\ny:%d,\nz:%d,\nradius:%d,\ncolor:%d\n}", sp.id,
	sp.x,
	sp.y,
	sp.z, sp.radius,
	sp.color);*/
	return (sp);
}
