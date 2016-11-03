/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 10:29:17 by dbreton           #+#    #+#             */
/*   Updated: 2016/10/27 10:29:20 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void     normalize_vector(t_vector *v) {
    double      length;
   // printf("Vector in: %f||%f||%f\n", v->x, v->y, v->z);

    length = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
    v->x /= length;
    v->y /= length;
    v->z /= length;
    if (isnan(v->x))
        v->x = 0;
    if (isnan(v->y))
        v->y = 0;
    if (isnan(v->z))
        v->z = 0;
    //printf("Vector out: %f||%f||%f\n", v->x, v->y, v->z);
}

void                    multiply_vec_double_des(t_vector *v, double n)
{
    v->x = v->x * n;
    v->y = v->y * n;
    v->z = v->z * n;
}
t_vector                mult_vec_double(t_vector v, double n)
{
    t_vector            res;

    res.x = v.x * n;
    res.y = v.y * n;
    res.z = v.z * n;
  //  printf("in:{%f||%f||%f||%f}\nres:{%f, %f, %f}\n", v.x, v.y, v.z, n, res.x, res.y, res.z);
    return (res);
}
void                    add_vector_des(t_vector *v1, t_vector v2)
{
    v1->x += v2.x;
    v1->y += v2.y;
    v1->z += v2.z;
}
t_vector                add_vector(t_vector v1, t_vector v2)
{
    t_vector            res;

    res.x = v1.x + v2.x;
    res.y = v1.y + v2.y;
    res.z = v1.z + v2.z;
	//printf("in:{%f,%f,%f||%f, %f, %f}\nres:{%f, %f, %f}\n", v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, res.x, res.y, res.z);
    return (res);
}