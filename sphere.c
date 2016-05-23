/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:56:03 by dbreton           #+#    #+#             */
/*   Updated: 2016/05/23 14:02:22 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int			inter(t_object *objs, t_vector *v) {
	(void)objs;
	(void)v;
	printf("sphere\n");
	return (1);
}

t_object			sphere(char **tmp) {
	t_object		sp;

	sp.inter = &inter;
	(void)tmp;
	return (sp);	
}
