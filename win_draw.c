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
        *d = (res[i] >= 0 && *d > res[i]) ? res[i] : *d;
        ++i;
    }

    return (d_init != *d);

}

static void     normalize_vector(t_vector *v) {
    double      length;

    length = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
    v->x /= length;
    v->y /= length;
    v->z /= length;
}

static t_vector     create_vector(t_mlx *s, int i, int j) {
    t_vector        v;
    float angle = tan(M_PI * 0.5 * 30 / 180.);
    //a = s->cam.xyz;
    //b = {WIN_MAX_X/2, WIN_MAX_Y/2};
    //c = {i/2, j/2}
    (void)i;
    (void)j;
    v.z = s->cam.rot_z;
   // v.y = s->cam.view_y - 0.35 * s->cam.vh * j;
    //v.x = s->cam.view_x + 0.5 * s->cam.vw * i ;
    v.x = 2 * ((float)(i + 0.5 + (s->cam.rot_x * M_PI/180)) / WIN_MAX_X) * angle * (WIN_MAX_X / WIN_MAX_Y);
    v.y = (1 - 2 * ((float)(j + 0.5 + (s->cam.rot_y * M_PI/180  )) / WIN_MAX_Y)) * angle;
    printf("pre-norm: %f||%f\n", v.x, v.y);
    normalize_vector(&v);
    printf("vec: %f||%f||%f\n", v.x, v.y, v.z);
    printf("angle: %f||%d||%d\n", angle, i, j);

    return (v);
}
int          get_inters(t_mlx *s, t_vector *v) {
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

    return ((d < 99999999.9f && d >= 0) ? 10000 : 0);
}

void                render_pic(t_mlx *s)
{
    int             i;
    int             j;
    int             tmp;

    j = 0;
    while (j < WIN_MAX_Y)
    {
        i = 0;
        while (i < WIN_MAX_X)
        {
            t_vector v = create_vector(s, i, j);
            tmp = get_inters(s, &v);
            //printf("%d\n", tmp);
            put_in_image(s, i, j, tmp*100000);
            ++i;
        }
        ++j;
    }

    (void)s;
}
