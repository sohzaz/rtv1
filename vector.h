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
	double				length;
}						t_vector;
void                    normalize_vector(t_vector *v);
void                    mult_vec_double_des(t_vector *v, double n);
t_vector                mult_vec_double(t_vector v, double n);
void                    add_vector_des(t_vector *v1, t_vector v2);
t_vector                add_vector(t_vector v1, t_vector v2);
t_vector                mult_vec_by_vec(t_vector v1, t_vector v2);
void                    mult_vec_by_vec_des(t_vector*v1, t_vector v2);
t_vector                sub_vec_by_vec(t_vector v1, t_vector v2);
t_vector                div_vec_by_double(t_vector v, double n);

#endif
