/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:27:14 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:27:40 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int				in_shadow(t_object *obj, t_object *v,
					t_vector *inter)
{
	int			res;
	double		*inter_res;
	double		i;
	t_vector	light_v;

	res = 0;
	i = 1.0f;
	light_v.x = v->x - inter->x;
	light_v.y = v->y - inter->y;
	light_v.z = v->z - inter->z;
	light_v.length = sqrt(pow(light_v.x, 2) + pow(light_v.y, 2)
						+ pow(light_v.z, 2));
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
