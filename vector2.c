/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:02:09 by dbreton           #+#    #+#             */
/*   Updated: 2016/10/27 11:02:13 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector                mult_vec_by_vec(t_vector v1, t_vector v2)
{
    t_vector            res;

    res.x = (v1.x + v1.y + v1.z) * v2.x;
    res.y = (v1.x + v1.y + v1.z) * v2.y;
    res.z = (v1.x + v1.y + v1.z) * v2.z;
    return (res);
}
void                    mult_vec_by_vec_des(t_vector*v1, t_vector v2)
{
    v1->x *= v2.x;
    v1->y *= v2.y;
    v1->z *= v2.z;
}
t_vector                sub_vec_by_vec(t_vector v1, t_vector v2)
{
    t_vector            res;

    res.x = v1.x - v2.x;
    res.y = v1.y - v2.y;
    res.z = v1.z - v2.z;
	//printf("in:{%f,%f,%f||%f, %f, %f}\nres:{%f, %f, %f}\n", v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, res.x, res.y, res.z);
    return (res);
}
t_vector                div_vec_by_double(t_vector v, double n)
{
	t_vector			res;

	res.x = v.x / n;
	res.y = v.y / n;
	res.z = v.z / n;
	return (res);
}


