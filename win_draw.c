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
    while (i <= (int)res[0]) {
        *d = (res[i] > 0 && *d > res[i]) ? res[i] : *d;
        ++i;
    }
    printf("%f\n", *d);
    return (d_init != *d);

}

static t_vector     create_vector(t_mlx *s, int i, int j) {
    t_vector        v;
    //a = s->cam.xyz;
    //b = {WIN_MAX_X/2, WIN_MAX_Y/2};
    //c = {i/2, j/2}
    v.x = (atan((sqrt(abs((WIN_MAX_X/2 - i)^2 )))/ (double)s->cam.focal) * (180/M_PI)) + (double)s->cam.rot_x;
    v.y = (atan((sqrt(abs((WIN_MAX_Y/2 - j)^2)))/ (double)s->cam.focal) * (180/M_PI)) + (double)s->cam.rot_y;
    v.z = s->cam.rot_z;
    return (v);
}
int          get_inters(t_mlx *s, t_vector *v) {
    int             i;
    double          d;
    double          *res;
    t_object        *closest;

    d = 500;
    i = 0;
    closest = NULL;
    (void)v;
    while (i < (s->obj_len)) {
        res = s->objects[i].inter(s->objects, v, s->cam, s->objects[i]);
        if (is_closest(&d, res) == 1)
            closest = &s->objects[i];
        i++;
    }
    return (closest != NULL);
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
            put_in_image(s, i, j, tmp);
            ++i;
        }
        ++j;
    }

    (void)s;
}
