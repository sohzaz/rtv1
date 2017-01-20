#include "sphere.h"


t_color	get_sphere_ambiant(t_object *src, t_object *self,
									t_vector *inter)
{
	(void)inter;
	t_vector light_v;
	light_v.x = inter->x - inter->x;
	light_v.y = inter->y - inter->y;
	light_v.z = inter->z - inter->z;
	light_v.length = sqrt(pow(light_v.x, 2) +
						  pow(light_v.y, 2) +
						  pow(light_v.z, 2));


	return(mult_color_double(
			mult_color(src->color, self->color),
			(self->kd * 0.1) * 0.1));
}
int 			in_shadow(t_object *obj, t_object *v,
					 t_vector *inter)
{
	int 		res;
	double		*inter_res;
	double 		i;
	t_vector 	light_v;

	res = 0;
	i = 1.0f;
	light_v.x = v->x - inter->x;
	light_v.y = v->y - inter->y;
	light_v.z = v->z - inter->z;
	light_v.length = sqrt(pow(light_v.x, 2) +
							 pow(light_v.y, 2) +
							 pow(light_v.z, 2));
	normalize_vector(&light_v);
	inter_res = obj->inter(*obj, &light_v, *inter);
	while (i < inter_res[0])
	{
		if (inter_res[(int)i] > 0.0f && inter_res[(int)i] < light_v.length)
		{
			res = 1;
			break;
		}
		++i;
	}
	//printf("inter_res: [%f, %f, %f]\nres: %d\nlen:%f\n", inter_res[0], inter_res[1], inter_res[2], res, light_v.length);
	return (res);
}

t_color 			get_sphere_diffuse(t_object *src, t_object *self,
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
	surface_normal = sphere_normal(inter, self);
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
void				comp_curr_diff(t_color* diffuse, int shadow,
								   t_color new_diff)
{
	if (shadow == 0)
	{
		if (isnan(diffuse->r))
		{
			diffuse->r = 0.0f;
			diffuse->g = 0.0f;
			diffuse->b = 0.0f;
		}
	}
	else
	{
		if (!isnan(diffuse->r))
		{
			*diffuse = add_color(*diffuse, new_diff);
		}
		else
			*diffuse = new_diff;
	}

}
