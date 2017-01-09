//
// Created by Drien BRETON on 1/3/17.
//
#include "fractol.h"

int 		tab_len(char **tab)
{
	int		i = 0;

	while (tab[i])
		++i;
	return (i);
}

t_object		create_new_src()
{
	t_object	res;

	res.x = 0;
	res.y = 0;
	res.z = 0;
	res.color.r  = NAN;
	res.color.g  = 0;
	res.color.b  = 0;
	return (res);
}
static void		mean_point(t_object *res, t_object *src)
{
	res->x = (res->x + src->x);
	res->y = (res->y + src->y);
	res->z = (res->z + src->z);
}
static void		mean_color(t_object *res, t_object *src)
{
	if (isnan(res->color.r))
	{
		res->color.r = src->color.r;
		res->color.g = src->color.g;
		res->color.b = src->color.b;
	} else {
		res->color.r = (res->color.r + src->color.r); // / 2.0f;
		res->color.g = (res->color.g + src->color.g); // / 2.0f;
		res->color.b = (res->color.b + src->color.b); // / 2.0f;
	}
	printf("mean color: {%f, %f, %f}\n", res->color.r, res->color.g, res->color.b);
}

t_object		get_total_illumination(t_mlx *s, t_object *self, t_vector inter)
{
	t_object res;
	int i;
	int j;
	int shadow;
	(void)self;

	i = 0;
	res = create_new_src();
	while (i < s->src_len) {
		j = 0;
		shadow = 0;
		while (j < s->obj_len) {
			shadow = (in_shadow(&s->objects[j], &s->sources[i], &inter));
			/*if (shadow)
				break;*/
			++j;
		}
		if (shadow == 0)
			mean_color(&res, &s->sources[i]);
		mean_point(&res, &s->sources[i]);

		++i;
	}
	return (res);
}
