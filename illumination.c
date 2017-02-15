/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:16:26 by dbreton           #+#    #+#             */
/*   Updated: 2017/02/15 14:45:23 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				comp_curr_diff(t_color *diffuse, int shadow,
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
			*diffuse = add_color(*diffuse, new_diff);
		else
			*diffuse = new_diff;
	}
}

int					in_shadow(t_object *obj, t_object *v,
		t_vector *inter)
{
	int				res;
	double			*inter_res;
	double			i;
	t_vector		light_v;

	res = 0;
	i = 1.0f;
	light_v.x = v->x - inter->x;
	light_v.y = v->y - inter->y;
	light_v.z = v->z - inter->z;
	light_v.length = sqrt(pow(light_v.x, 2) + pow(light_v.y, 2) +
			pow(light_v.z, 2));
	normalize_vector(&light_v);
	inter_res = obj->inter(*obj, &light_v, *inter);
	while (i < inter_res[0])
	{
		if (inter_res[(int)i] > 0.0f && inter_res[(int)i] < light_v.length)
		{
			res = 1;
			break ;
		}
		++i;
	}
	free(inter_res);
	return (res);
}

static void			comp_curr_spec(t_color *spec, int shadow,
		t_color new_spec)
{
	if (shadow == 0)
	{
		if (isnan(spec->r))
		{
			spec->r = 0.0f;
			spec->g = 0.0f;
			spec->b = 0.0f;
		}
	}
	else
	{
		if (!isnan(spec->r))
			*spec = add_color(*spec, new_spec);
		else
			*spec = new_spec;
	}
}

t_color				get_color(t_mlx *s, t_object *self, t_vector inter)
{
	int				ti[3];
	t_color			colors[2];

	ti[0] = 0;
	ti[2] = 0;
	colors[0].r = NAN;
	colors[1].r = NAN;
	while (ti[0] < s->src_len)
	{
		ti[1] = 0;
		while (ti[1] < s->obj_len)
		{
			ti[2] = !(in_shadow(&s->objects[ti[1]],
						&s->srcs[ti[0]], &inter));
			if (ti[2] == 0)
				break ;
			++ti[1];
		}
		comp_curr_diff(&colors[0], ti[2],
				self->diffuse(&s->srcs[ti[0]], self, &inter));
		comp_curr_spec(&colors[1], ti[2],
				self->specular(&s->srcs[ti[0]], self, &inter, &s->cam.c));
		++ti[0];
	}
	return (add_color(colors[0], colors[1]));
}
