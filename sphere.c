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
#include "sphere.h"

static double           *calc_result(double a, double b, double d)
{
    double *res;

    res = (double *)malloc(sizeof(double) * 3);
    res[0] = -1.0f;
    if (d == 0)
    {
        res[0] = 1.0f;
        res[1] = (-1 * b) / (2 * a);
    }
    else if (d > 0)
    {
        res[0] = 2.0f;
        res[1] = ((-1 * b) - sqrt(d)) / (2 * a);
        res[2] = ((-1 * b) + sqrt(d)) / (2 * a);

    }
    printf("out:%f||%f||%f\n", res[0], res[1], res[2]);
    return(res);
}

t_vector			sphere_normal(t_vector *intersect, t_object *self)
{
	t_vector			res;
	t_vector			center;

	center.x = self->x;
	center.y = self->y;
	center.z = self->z;
	res = sub_vec_by_vec(*intersect, center);
	normalize_vector(&res);
	return (res);
}

static int 				sphere_color(t_mlx *s, t_object *self, t_vector inter)
{
	int 			i;
	int 			j;
	int 			shadow;
	double 			diffuse;
	/*int 			phong;*/

	i = 0;
	diffuse = 0;
	while (i < s->src_len)
	{
		j = 0;
		while (j < s->obj_len)
		{
			shadow = !(in_shadow(&s->objects[j], &s->sources[i], &inter));
			diffuse += get_sphere_diffuse(&s->sources[i], self, &inter) * shadow;
			printf("shadow: %d\ndiffuse:%f\n", shadow, diffuse);
			++j;
		}
		++i;
	}
	return (diffuse);
}

static double			*sphere_inter(t_object self, t_vector *v,
									   t_vector org)
{
    double a;
    double b;
    double c;
    double d;

    a = pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2);
    b = 2 * (v->x * (org.x - self.x) + v->y * (org.y - self.y) + v->z * (org.z - self.z));
    c = (pow(org.x - self.x, 2) + pow(org.y - self.y, 2) + pow(org.z - self.z, 2)) - pow(self.radius, 2);
    d = b * b - 4 * (a * c);

    printf("in:%.10f||%.10f||%.10f\n", a, b, c);

    return (calc_result(a, b, d));
}

t_object			sphere(char **tmp)
{
	t_object		sp;
	sp.normal = &sphere_normal;
	sp.inter = &sphere_inter;
	sp.get_color = &sphere_color;
    sp.id = ft_atoi(tmp[0]);
    sp.x = ft_atoi(tmp[2]);
    sp.y = ft_atoi(tmp[3]);
    sp.z = ft_atoi(tmp[4]);
    sp.rot_x = ft_atoi(tmp[5]);
    sp.rot_y = ft_atoi(tmp[6]);
    sp.rot_z = ft_atoi(tmp[7]);
    sp.radius = ft_atoi(tmp[8]);
	sp.color = ft_atoi(tmp[1]);
	sp.kd = ft_atoi(tmp[10]);
	printf("sphere:{id:%d,\nx:%d,\ny:%d,\nz:%d,\nradius:%d,\ncolor:%d\n}", sp.id,
	sp.x,
	sp.y,
	sp.z, sp.radius,
	sp.color);
	return (sp);
}
