/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:57:00 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/20 16:57:02 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
t_object	    get_obj_type(char **tmp) {
	t_object        nil;

	nil.type = -127;
	if (tab_len(tmp) == 11)
	{
		if (ft_strcmp(tmp[9], "sphere") == 0)
			return (sphere(tmp));
		else if (ft_strcmp(tmp[9], "plane") == 0)
			return (plane(tmp));
		else if (ft_strcmp(tmp[9], "cylinder") == 0)
			return (cylinder(tmp));
		else if (ft_strcmp(tmp[9], "cone") == 0)
			return (cone(tmp));
	}
	return (nil);
}

