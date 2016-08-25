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
static t_vector     create_vector(t_mlx *s, int i, int j) {
    t_vector        v;
    //a = s->cam.xyz;
    //b = {WIN_MAX_X/2, WIN_MAX_Y/2};
    //c = {i/2, j/2}


    v.x = (atan((sqrt(abs((WIN_MAX_X/2 - i)^2 + (WIN_MAX_Y/2 - j)^2)))/ (double)s->cam.focal) * (180/M_PI)) + (double)s->cam.rot_x;
    v.y = (atan((sqrt(abs((WIN_MAX_X/2 - i)^2 + (WIN_MAX_Y/2 - j)^2)))/ (double)s->cam.focal) * (180/M_PI)) + (double)s->cam.rot_y;
    v.z = s->cam.rot_z;


    return (v);
}

void                render_pic(t_mlx *s)
{
    int             i;
    int             j;

    j = 0;
    while (j < WIN_MAX_Y)
    {
        i = 0;
        while (i < WIN_MAX_X)
        {
            t_vector v = create_vector(s, i, j);
            put_in_image(s, i, j, /*s->objects[0].inter(NULL, &v)*/ (int)((v.x + v.y) * 100000));
            printf("%d||%d||%f||%f||%f\n",i,j, v.x, v.y, v.z);
            ++i;
        }
        ++j;
    }

    (void)s;
}
