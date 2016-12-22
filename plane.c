/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:59:13 by dbreton           #+#    #+#             */
/*   Updated: 2016/08/25 15:59:21 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "sphere.h"

static t_color			get_plane_diffuse(t_object *src, t_object *self,
											t_vector *inter)
{
	t_vector	light_v;
	double 		l_dot_normal;
	t_color		tmp;

	light_v.x = src->x - inter->x;
	light_v.y = src->y - inter->y;
	light_v.z = src->z - inter->z;
	light_v.length = sqrt(light_v.x * light_v.x + light_v.y * light_v.y
						  + light_v.z * light_v.z);
	normalize_vector(&light_v);
	l_dot_normal = fabs(dot(&self->dir, &light_v));
	//printf("pl_dot_normal: %f\n", l_dot_normal);
	tmp = mult_color_double(
			mult_color(src->color, self->color),
			((self->kd / 100) * l_dot_normal) /*/
			pow(light_v.length, 2)*/);
/*	printf("pl_src_col:{%f, %f, %f}\n", src->color.r, src->color.g, src->color.b);
	printf("pl_obj_col:{%f, %f, %f}\n", self->color.r, self->color.g, self->color.b);
	printf("pl_diffuse:{%f, %f, %f}\n", tmp.r, tmp.g, tmp.b);*/
	return (tmp);
}

static double 			plane_color(t_mlx *s, t_object *self, t_vector inter)
{
	int 			i;
	int 			j;
	int 			shadow;
	t_color			diffuse;
	//t_color			ambiant;
	/*int 			phong;*/

	i = 0;
	diffuse.r = NAN;
	while (i < s->src_len)
	{
		j = 0;
		while (j < s->obj_len)
		{
			shadow = !(in_shadow(&s->objects[j], &s->sources[i], &inter));
			comp_curr_diff(&diffuse, shadow,
						   get_plane_diffuse(&s->sources[i], self, &inter));
			/*	ambiant = (ambiant.r) ? get_sphere_ambiant(&s->sources[i],
														 self, &inter) :
						add_color(ambiant, get_sphere_ambiant(&s->sources[i],
															  self, &inter));*/
			//printf("shadow:%d\n\n", shadow);
			++j;
		}
		++i;
	}
	//	return (get_color_value(add_color(diffuse, ambiant)));
	return (get_color_value(diffuse));
}

static double			*plane_inter(t_object self, t_vector *v, t_vector org) {
	double 				v_dot;
	//double 				t;
	double 				*res;
	t_vector			n;
	t_vector			v0;

	v_dot = dot(v, &self.dir);
	n.z = -1.0f;
	v0.x = org.x - self.x;
	v0.y = org.y - self.y;
	v0.z = org.z - self.z;
	res = (double *)malloc(sizeof(double) * 3);
	if (v_dot > 0.0f)
	{
			res[0] = 1.0f;
		//printf("plane_vecs:{v0:{%f,%f,%f},self.dir{%f,%f,%f}\n", v0.x, v0.y, v0.z, self.dir.x, self.dir.y, self.dir.z);
			res[1] = -((self.dir.x * v0.x + self.dir.y * v0.y + self.dir.z * v0.z) / (self.dir.x * v->x + self.dir.y * v->y + self.dir.z * v->z));
	//	printf("plane_inter: %f\n", res[1]);
	}
	else
		res[0] = -1.0f;

    //return closest point distance
    return (res);
}

t_object			plane(char **tmp) {
    t_object		pl;


    pl.inter = &plane_inter;
	pl.get_color = &plane_color;
    pl.id = ft_atoi(tmp[0]);
    pl.x = ft_atoi(tmp[2]);
    pl.y = ft_atoi(tmp[3]);
    pl.z = ft_atoi(tmp[4]);
    pl.dir.x = ft_atoi(tmp[5]);
    pl.dir.y = ft_atoi(tmp[6]);
    pl.dir.z = ft_atoi(tmp[7]);
	pl.kd = ft_atoi(tmp[10]);
    normalize_vector(&pl.dir);
	pl.color = create_color(tmp[1]);

    return (pl);
}


