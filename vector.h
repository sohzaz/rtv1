/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 10:28:56 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:14:40 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void					normalize_vector(t_vector *v);
t_vector				mult_vec_double(t_vector v, double n);
t_vector				add_vector(t_vector v1, t_vector v2);
t_vector				mult_vec_by_vec(t_vector v1, t_vector v2);
t_vector				sub_vec_by_vec(t_vector v1, t_vector v2);
double					dot(t_vector *v1, t_vector *v2);

#endif
