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
static t_object	    get_obj_type(char **tmp) {
    t_object        nil;

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
static void		    body_parse(t_mlx *s, int fd, int *l)
{
    char		    *line;
    char		    **tmp;
    int			    tot_len;
    int			    o;

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

static void         cam_vector_compute(t_mlx *s, t_vector view_dir)
{
    t_vector        up;
	t_vector		right;

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
	right.x = 1.0f;
	right.y = 0.0f;
	right.z = 0.0f;
	printf("view_dir:{%f, %f, %f}\n", view_dir.x, view_dir.y, view_dir.z);
    s->cam.vhw = tan(60);
	//s->cam.vhw = 0.3f;
	//s->cam.vhh = 0.05f;
    s->cam.aspect = (double)WIN_MAX_X / (double)WIN_MAX_Y;
    s->cam.vhh = s->cam.vhw * s->cam.aspect;
	/*s->cam.vv = mult_vec_by_vec(view_dir, up);
	s->cam.vu = mult_vec_by_vec(s->cam.vv, view_dir);
	normalize_vector(&s->cam.vu);
	normalize_vector(&s->cam.vv);
	printf("vu:{%f, %f, %f}\n", s->cam.vu.x, s->cam.vu.y, s->cam.vu.z);
	printf("vv:{%f, %f, %f}\n", s->cam.vv.x, s->cam.vv.y, s->cam.vv.z);*/
	s->cam.vu = up;
	s->cam.vv = right;
	printf("vhh: %f, vhw: %f, aspect:%f\n", s->cam.vhh, s->cam.vhw, s->cam.aspect);
	s->cam.vp = add_vector(s->cam.c, sub_vec_by_vec(
			add_vector(
			mult_vec_double(view_dir, s->cam.focal),
			mult_vec_double(up, s->cam.vhw/2.0f)),
			mult_vec_double(right, s->cam.vhh / 2.0f)));

 /*   s->cam.vp = sub_vec_by_vec(s->cam.lp, sub_vec_by_vec(
			mult_vec_double(s->cam.vu, s->cam.vhw),
			mult_vec_double(s->cam.vv, s->cam.vhh)
	));
	s->cam.viy = mult_vec_double(s->cam.vu,
								 (2.0f * s->cam.vhh) / (double)WIN_MAX_Y);
	s->cam.vix = mult_vec_double(s->cam.vv,
								 (2.0f * s->cam.vhw) / (double)WIN_MAX_X);
								 */
/*	s->cam.vix = mult_vec_double(right, s->cam.vhw / (float)WIN_MAX_X);
	s->cam.viy = mult_vec_double(up, s->cam.vhh / (float)WIN_MAX_Y);*/

	printf("vp:{%f, %f, %f}\n", s->cam.vp.x, s->cam.vp.y, s->cam.vp.z);
/*	printf("vix:{%f, %f, %f}\n", s->cam.vix.x, s->cam.vix.y, s->cam.vix.z);
	printf("viy:{%f, %f, %f}\n", s->cam.viy.x, s->cam.viy.y, s->cam.viy.z);*/


}

static void         camera_parse(t_mlx *s, int fd, int *l)
{
    char            *line;
    char            **tmp;
    t_vector        view_dir;

    while (*l != 2 && get_next_line(fd, &line) > 0)
        if (line[0] != '#')
        {
            tmp = ft_strsplit(line, ' ');
            s->cam.c.x = ft_atoi(tmp[0]);
            s->cam.c.y = ft_atoi(tmp[1]);
            s->cam.c.z = ft_atoi(tmp[2]);
            s->cam.lp.x = ft_atoi(tmp[4]);
            s->cam.lp.y = ft_atoi(tmp[5]);
            s->cam.lp.z = ft_atoi(tmp[6]);
			printf("cp:{%f, %f, %f}\n", s->cam.c.x, s->cam.c.y, s->cam.c.z);
			printf("lp:{%f, %f, %f}\n", s->cam.lp.x, s->cam.lp.y, s->cam.lp.z);
            view_dir = sub_vec_by_vec(s->cam.lp, s->cam.c);
			s->cam.focal = sqrt(pow(view_dir.x - s->cam.x, 2) +
								pow(view_dir.y - s->cam.y, 2) +
								pow(view_dir.z - s->cam.z, 2));
			printf("focal:%f\n", s->cam.focal);
			printf("sqrt(%f + %f + %f)\n", pow(view_dir.x - s->cam.x, 2),
				   pow(view_dir.y - s->cam.y, 2),
				   pow(view_dir.z - s->cam.z, 2));
			normalize_vector(&view_dir);
            cam_vector_compute(s, view_dir);
            ++*l;
            free(line);
        }
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
