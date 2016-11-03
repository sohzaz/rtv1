/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:20:16 by dbreton           #+#    #+#             */
/*   Updated: 2015/12/29 11:55:12 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//TODO implement raytracing algo
static int      is_closest(double *d, double *res) {
    int         i;
    double      d_init;

    i = 1;
    d_init = *d;
  //  printf("%f\n", d_init);
    while (i <= (int)res[0]) {
       //printf("%f||%f\n", res[i], *d);
        *d = (res[i] > 0 && *d > res[i]) ? res[i] : *d;
        ++i;
    }

    return (d_init != *d);

}

static t_vector     create_vector(t_mlx *s, int i, int j) {
    t_vector        v;
	t_vector		vpp;



	vpp = add_vector(s->cam.vp, sub_vec_by_vec(
			mult_vec_double(mult_vec_double(s->cam.vv, 100* (s->cam.vhw / (float) WIN_MAX_X)), (double)i),
			mult_vec_double(mult_vec_double(s->cam.vu, s->cam.vhh / (float) WIN_MAX_Y), (double)j)
	));

	printf("vpp:{%f, %f, %f}\n", vpp.x, vpp.y, vpp.z);
	//v = sub_vec_by_vec(vpp, s->cam.c);
	v = vpp;

    printf("ij: %d||%d\n", i, j);
	//printf("v:{%f, %f, %f}\n", v.x, v.y, v.z);
    normalize_vector(&v);
    printf("vec: %f||%f||%f\n", v.x, v.y, v.z);
    return (v);
}
int         		get_inters(t_mlx *s, t_vector *v) {
    int             i;
    double          d;
    double          *res;
    t_object        *closest;

    d = 99999999.9f;
    i = 0;
    closest = NULL;
    (void)v;
    while (i < (s->obj_len)) {
        //printf("%f\n", d);
        res = s->objects[i].inter(s->objects, v, s->cam, s->objects[i]);
        if (is_closest(&d, res) == 1)
            closest = &s->objects[i];
        i++;
    }
    printf("d:%f\n", d);

    return ((d < 99999999.9f) ? 10000 : 0);
}

void                render_pic(t_mlx *s)
{
    int             i;
    int             j;
    int             tmp;
	t_vector		v;

    j = 0;
    while (j < WIN_MAX_Y)
    {
        i = 0;
        while (i < WIN_MAX_X)
        {
			v = create_vector(s, i, j);
			printf("V:{%f, %f, %f}\n", v.x, v.y, v.z);
            tmp = get_inters(s, &v);

            put_in_image(s, i, j, tmp*100000);
            ++i;
        }
        ++j;
    }

    (void)s;
}
