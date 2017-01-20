/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 12:45:34 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/20 17:07:38 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				sources_parse(t_mlx *s, int fd, int *l)
{
	char			*line;
	char			**tmp;
	int				tot_len;
	int				o;

	tot_len = s->src_len + *l;
	o = 0;
	while (*l < tot_len && get_next_line(fd, &line) > 0)
		if (line[0] != '#')
		{
			tmp = ft_strsplit(line, ' ');
			++*l;
			s->sources[o] = source(tmp);
			++o;
		}
}

static void			body_parse(t_mlx *s, int fd, int *l)
{
	char			*line;
	char			**tmp;
	int				tot_len;
	int				o;

	tot_len = s->obj_len + *l;
	o = 0;
	while (*l < tot_len && get_next_line(fd, &line) > 0 )
		if (line[0] != '#')
		{
			tmp = ft_strsplit(line, ' ');
			++*l;
			s->objects[o] = get_obj_type(tmp);
			if (s->objects[o].type == -127) {
				ft_exit(2, "file content mismatch\n");
			}
			free(tmp);
			++o;
		}
	sources_parse(s, fd, l);
}

static void			cam_vector_compute(t_mlx *s, t_vector view_dir)
{
	t_vector		up;

	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;
	s->cam.vhw = tan(s->cam.fov / 2);
	s->cam.aspect = (double)WIN_MAX_Y / (double)WIN_MAX_X;
	s->cam.vhh = s->cam.vhw * s->cam.aspect;
	s->cam.vu = mult_vec_by_vec(view_dir, up);
	s->cam.vv = mult_vec_by_vec(s->cam.vu, view_dir);
	normalize_vector(&s->cam.vu);
	normalize_vector(&s->cam.vv);
	s->cam.vp = sub_vec_by_vec(s->cam.lp, sub_vec_by_vec(
			mult_vec_double(s->cam.vu, s->cam.vhw),
			mult_vec_double(s->cam.vv, s->cam.vhh)
	));
	s->cam.viy = mult_vec_double(
			mult_vec_double(s->cam.vv,
							(2.0f * s->cam.vhh)), 1.0f / (double)WIN_MAX_Y);
	s->cam.vix = mult_vec_double(
			mult_vec_double(s->cam.vu,
							(2.0f * s->cam.vhw)), 1.0f / (double)WIN_MAX_X);
	s->cam.ix = s->cam.vhw / (float)WIN_MAX_X;
	s->cam.iy = s->cam.vhh / (float)WIN_MAX_Y;
}

static void			camera_parse(t_mlx *s, int fd, int *l)
{
	char            *line;
	char            **tmp;
	t_vector        view_dir;

	while (*l != 2 && get_next_line(fd, &line) > 0)
		if (line[0] != '#')
		{
			tmp = ft_strsplit(line, ' ');
			if (tab_len(tmp) != 7 || isnan(s->cam.c.x = ft_atoi(tmp[0])) ||
			isnan(s->cam.c.y = ft_atoi(tmp[1])) ||
			isnan(s->cam.c.z = ft_atoi(tmp[2])) ||
			isnan(s->cam.lp.x = ft_atoi(tmp[4])) ||
			isnan(s->cam.lp.y = ft_atoi(tmp[5])) ||
			isnan(s->cam.lp.z = ft_atoi(tmp[6])) ||
			isnan(s->cam.fov = ft_atoi(tmp[3])))
				ft_exit(1, "incorrect camera settings\n");
			view_dir = sub_vec_by_vec(s->cam.lp, s->cam.c);
			s->cam.focal = sqrt(pow(view_dir.x - s->cam.c.x, 2) +
								pow(view_dir.y - s->cam.c.y, 2) +
								pow(view_dir.z - s->cam.c.z, 2));
			normalize_vector(&view_dir);
			cam_vector_compute(s, view_dir);
			++*l;
			free(line);
		}
	body_parse(s, fd, l);
}

void				parse(t_mlx *s, int fd) {
	int         	l;
	char        	*line;
	char        	**tmp;
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
			free(line);
		}
	camera_parse(s, fd, &l);
}
