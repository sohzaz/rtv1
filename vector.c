/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 10:29:17 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:08:43 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			comp_vector_length(t_vector *v)
{
	v->length = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}

void			normalize_vector(t_vector *v)
{
	comp_vector_length(v);
	v->x /= v->length;
	v->y /= v->length;
	v->z /= v->length;
	if (isnan(v->x))
		v->x = 0.0f;
	if (isnan(v->y))
		v->y = 0.0f;
	if (isnan(v->z))
		v->z = 0.0f;
}

t_vector		mult_vec_double(t_vector v, double n)
{
	t_vector	res;

	res.x = v.x * n;
	res.y = v.y * n;
	res.z = v.z * n;
	return (res);
}

t_vector		add_vector(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}
