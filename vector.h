/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 10:28:56 by dbreton           #+#    #+#             */
/*   Updated: 2016/10/27 10:29:12 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * add_vector_des: destructive addition, will store the result in v1
 * add_vector: non destructive addition, will return a new t_vector structure
 */
#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdio.h>

typedef struct			s_vector{
    double				x;
    double				y;
    double				z;
}						t_vector;
void                    normalize_vector(t_vector *v);
void                    multiply_vector_des(t_vector *v, double n);
t_vector                multiply_vector(t_vector v, double n);
void                    add_vector_des(t_vector *v1, t_vector v2);
t_vector                add_vector(t_vector v1, t_vector v2);

#endif
