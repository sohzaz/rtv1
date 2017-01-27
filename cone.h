/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:43:26 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 16:43:55 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_CONE_H
# define RTV1_CONE_H
# include "fractol.h"
# include "sphere.h"
# include "cylinder.h"

t_vector		cone_normal(t_vector *intersect, t_object *self);

t_color			cone_diffuse(t_object *src, t_object *self,
									t_vector *inter);
#endif
