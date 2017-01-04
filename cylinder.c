//
// Created by Drien BRETON on 1/4/17.
//

#include "cylinder.h"

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

static double 		*cyl_inter(t_object self, t_vector *v,
								t_vector org)
{
	double			params[4];
	double 			ab;
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

t_object			cylinder(char **tmp)
{
	t_object		sp;

	//sp.normal = &sphere_normal;
	sp.inter = &cyl_inter;
	//sp.get_color = &sphere_color;
	sp.id = ft_atoi(tmp[0]);
	sp.x = ft_atoi(tmp[2]);
	sp.y = ft_atoi(tmp[3]);
	sp.z = ft_atoi(tmp[4]);
	sp.dir.x = ft_atoi(tmp[5]);
	sp.dir.y = ft_atoi(tmp[6]);
	sp.dir.z = ft_atoi(tmp[7]);
	sp.radius = ft_atoi(tmp[8]);
	sp.color = create_color(tmp[1]);
	sp.kd = ft_atoi(tmp[10]);

	/*printf("sphere:{id:%d,\nx:%d,\ny:%d,\nz:%d,\nradius:%d,\ncolor:%d\n}", sp.id,
	sp.x,
	sp.y,
	sp.z, sp.radius,
	sp.color);*/
	return (sp);
}
