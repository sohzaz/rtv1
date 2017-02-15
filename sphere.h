/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:51:05 by dbreton           #+#    #+#             */
/*   Updated: 2017/02/15 14:38:31 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "rtv1.h"

t_vector		sphere_normal(t_vector *intersect, t_object *self);
t_color			get_sphere_diffuse(t_object *src, t_object *self,
		t_vector *inter);
double			sphere_color(t_mlx *s, t_object *self, t_vector inter);
t_color			sphere_specular(t_object *src, t_object *self,
		t_vector *inter, t_vector *v);

#endif
