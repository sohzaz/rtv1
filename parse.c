/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 12:45:34 by dbreton           #+#    #+#             */
/*   Updated: 2016/05/23 14:35:25 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static t_object	get_obj_type(char **tmp) {
    t_object nil;

    nil.type = -127;
    if (ft_strcmp(tmp[9], "sphere") == 0) {
        write(2, "sphere\n", 7);
        return (sphere(tmp));
    }
    else if (ft_strcmp(tmp[9], "plane") == 0) {
        write(2, "plane\n", 6);
        return (plane(tmp));
    }
    return (nil);
}
static void		body_parse(t_mlx *s, int fd, int *l)
{
    char		*line;
    char		**tmp;
    int			tot_len;
    int			o;

    tot_len = s->obj_len + s->src_len + *l;
    o = 0;
    while (*l < tot_len && get_next_line(fd, &line) > 0 )
        if (line[0] != '#')
        {
            tmp = ft_strsplit(line, ' ');
            ++*l;
            if (tmp[1][0] == '0' && o < s->obj_len)
            {
                s->objects[o] = get_obj_type(tmp);
                ++o;
            }
        }
}

static void    camera_parse(t_mlx *s, int fd, int *l)
{
    char        *line;
    char        **tmp;

    while (*l != 2 && get_next_line(fd, &line) > 0)
        if (line[0] != '#')
        {
            tmp = ft_strsplit(line, ' ');
            s->cam.x = ft_atoi(tmp[0]);
            s->cam.y = ft_atoi(tmp[1]);
            s->cam.z = ft_atoi(tmp[2]);
            s->cam.focal = ft_atoi(tmp[3]);
            s->cam.rot_x = ft_atoi(tmp[4]);
            s->cam.rot_y = ft_atoi(tmp[5]);
            s->cam.rot_z = ft_atoi(tmp[6]);
            //TODO refactor
            s->cam.vw = tan(30);
            s->cam.vh = (WIN_MAX_X / WIN_MAX_Y) * s->cam.vw;
            s->cam.vpx = (s->cam.x + cos(s->cam.rot_x) * s->cam.focal) - s->cam.vw;
            s->cam.vpy = (s->cam.y + sin(s->cam.rot_y) * s->cam.focal) - s->cam.vh;
            s->cam.vpz = s->cam.z;
            s->cam.view_x = (int)(s->cam.x +
                    ((s->cam.rot_x * s->cam.focal) - (0.5 * (s->cam.vw/2))));
            s->cam.view_y = (int)(s->cam.y +
                    ((s->cam.rot_y * s->cam.focal) + (0.35 * (s->cam.vh/2))));

            ++*l;
            free(line);
        }
	printf("cam: %f||%f||%f||%d\n", s->cam.vpx, s->cam.vpy, s->cam.vpz, s->cam.view_y);
    body_parse(s, fd, l);
}

void            parse(t_mlx *s, int fd) {
    int         l;
    char        *line;
    char        **tmp;
    l = 0;
    while (l != 1 && get_next_line(fd, &line) > 0)
        if (line[0] != '#')
        {
            tmp = ft_strsplit(line, '/');
            s->src_len = ft_atoi(tmp[0]);
            s->obj_len = ft_atoi(tmp[1]);
            s->sources = (t_object *)malloc(sizeof(t_object) * (s->src_len + 1));
            s->objects = (t_object *)malloc(sizeof(t_object) * (s->obj_len + 1));

            ++l;
            //printf("%s\n", line);
            free(line);
        }
    camera_parse(s, fd, &l);
}
