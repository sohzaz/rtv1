#include "sphere.h"

int 			in_shadow(t_object *obj, t_object *v,
					 t_vector *inter)
{
	int 		res;
	double		*inter_res;
	double 		i;
	t_vector 	light_v;

	res = 0;
	i = 0.0f;
	light_v.x = v->x - inter->x;
	light_v.y = v->y - inter->y;
	light_v.z = v->z - inter->z;
	light_v.length = sqrt(pow(v->x - inter->x, 2) +
							 pow(v->y - inter->y, 2) +
							 pow(v->z - inter->z, 2));
	normalize_vector(&light_v);
	inter_res = obj->inter(*obj, &light_v, *inter);
	while (i < inter_res[0])
	{
		if (inter_res[(int)i] > 0 && inter_res[(int)i] < light_v.length)
			res = 1;
		++i;
	}
	printf("inter_res: [%f, %f, %f]\n", inter_res[0], inter_res[1], inter_res[2]);
	return (res);
}
