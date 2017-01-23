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
	free(inter_res);
	//printf("inter_res: [%f, %f, %f]\nres: %d\nlen:%f\n", inter_res[0], inter_res[1], inter_res[2], res, light_v.length);
	return (res);
}


