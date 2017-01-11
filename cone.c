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
static t_vector		calc_m(t_object self)
{
	t_vector		res;
	t_matrix		m;
	double 			dd;

	m = new_matrix(3, 3);
	m.cont[0][0] = -1.0f * pow(cos(self.radius * M_PI / 180.0), 2);
	m.cont[1][1] = -1.0f * pow(cos(self.radius * M_PI / 180.0), 2);
	m.cont[2][2] = -1.0f * pow(cos(self.radius * M_PI / 180.0), 2);
	dd = dot(&self.dir, &self.dir);
	add_matrix_double(&m, dd);
	res.x = 0;


	return(res);
}
static double 		*cone_inter(t_object self, t_vector *v,
								t_vector org)
{
	double			params[4];
	double 			ab;
	t_vector		aob;
	t_vector		vab;
	t_vector		ao;

	ao.x = org.x - self.x ;
	ao.y = org.y - self.y ;
	ao.z = org.z - self.z ;
	ab = dot(&self.dir, &self.dir) - pow(cos(self.radius * M_PI / 180.0), 2);
	(void)calc_m(self);
	aob = mult_vec_double(*v, ab);
	vab = mult_vec_double(ao, ab);
	params[0] = 0.0f;
	params[1] = 2.0f  * dot(v, &vab);
	params[2] = dot(&ao, &vab);
	params[3] = params[1] * params[1] - (4 * params[0] * params[2]);
	printf("params:\n[0]%f\n[1]%f\n[2]%f\n[3]%f\nab:%f\nv:{\n\tx:%f,\n\ty:%f,\n\tz:%f\n}\n", params[0], params[1], params[2],params[3], ab, v->x, v->y, v->z);
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

