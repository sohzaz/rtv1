/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:02:09 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:12:04 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector				mult_vec_by_vec(t_vector v1, t_vector v2)
{
	t_vector			res;

	res.x = v1.y * v2.z - v2.y * v1.z;
	res.y = v2.x * v1.z - v2.z * v1.x;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

t_vector				sub_vec_by_vec(t_vector v1, t_vector v2)
{
	t_vector			res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vector				div_vec_by_double(t_vector v, double n)
{
	return (mult_vec_double(v, 1.0f / n));
}

double					dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
