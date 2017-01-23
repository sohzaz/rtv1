/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:49:48 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/20 16:50:28 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_CYLINDER_H
# define RTV1_CYLINDER_H
# include "fractol.h"
# include "sphere.h"

t_color 			get_cyl_diffuse(t_object *src, t_object *self,
								   t_vector *inter);
t_vector			cyl_normal(t_vector *inter, t_object *self);



#endif
