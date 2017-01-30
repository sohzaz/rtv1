/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:16:26 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 15:16:30 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

t_color				get_color(t_mlx *s, t_object *self, t_vector inter)
{
	int				i;
	int				j;
	int				shadow;
	t_color			diffuse;

	i = 0;
	shadow = 0;
	diffuse.r = NAN;
	while (i < s->src_len)
	{
		j = 0;
		while (j < s->obj_len)
		{
			shadow = !(in_shadow(&s->objects[j], &s->sources[i], &inter));
			if (shadow == 0)
				break ;
			++j;
		}
		comp_curr_diff(&diffuse, shadow,
					self->diffuse(&s->sources[i], self, &inter));
		++i;
	}
	return (diffuse);
}
