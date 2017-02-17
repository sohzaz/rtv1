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

#include "rtv1.h"

void				sources_parse(t_mlx *s, int fd, int *l)
{
	char			*line;
	char			**tmp;
	int				tot_len;
	int				o;

	tot_len = s->src_len + *l;
	o = 0;
	while (*l < tot_len && get_next_line(fd, &line) > 0)
	{
		if (line[0] != '#' && ft_strlen(line) > 0)
		{
			tmp = ft_strsplit(line, ' ');
			++*l;
			line_validate(&tmp, 6);
			s->srcs[o] = source(tmp);
			s->all[*l - 3] = &s->objects[o];
			s->all[*l - 2] = NULL;
			++o;
			clear_tab(tmp);
		}
		free(line);
	}
	transform_parse(s, fd, l);
}

static void			body_parse(t_mlx *s, int fd, int *l)
{
	char			*line;
	char			**tmp;
	int				tot_len;
	int				o;

	tot_len = s->obj_len + *l;
	o = 0;
	while (*l < tot_len && get_next_line(fd, &line) > 0)
	{
		if (line[0] != '#' && ft_strlen(line) > 0)
		{
			tmp = ft_strsplit(line, ' ');
			++*l;
			s->objects[o] = get_obj_type(tmp);
			if (s->objects[o].type == 127)
				ft_exit(2, "object content mismatch\n");
			s->all[*l - 3] = &s->objects[o];
			s->all[*l - 2] = NULL;
			++o;
			clear_tab(tmp);
		}
		free(line);
	}
	sources_parse(s, fd, l);
}

static void			cam_vector_compute(t_mlx *s, t_vector view_dir)
{
	t_vector		up;

	up.x = 0.0f;
	up.y = -1.0f;
	up.z = 0.0f;
	s->cam.vhw = tan((s->cam.fov / 2) * M_PI / 180.0f);
	s->cam.aspect = (double)WIN_MAX_Y / (double)WIN_MAX_X;
	s->cam.vhh = s->cam.vhw * s->cam.aspect;
	s->cam.vu = mult_vec_by_vec(view_dir, up);
	s->cam.vv = mult_vec_by_vec(s->cam.vu, view_dir);
	normalize_vector(&s->cam.vu);
	normalize_vector(&s->cam.vv);
	s->cam.vp = sub_vec_by_vec(s->cam.lp, add_vector(
			mult_vec_double(s->cam.vu, s->cam.vhw),
			mult_vec_double(s->cam.vv, s->cam.vhh)));
	s->cam.viy = mult_vec_double(
		s->cam.vv, (2.0f * s->cam.vhh) / (double)WIN_MAX_Y);
	s->cam.vix = mult_vec_double(
			s->cam.vu, (2.0f * s->cam.vhw) / (double)WIN_MAX_X);
}

static void			camera_parse(t_mlx *s, int fd, int *l)
{
	char			*line;
	char			**tmp;
	t_vector		view_dir;

	while (*l != 2 && get_next_line(fd, &line) > 0)
	{
		if (line[0] != '#' && ft_strlen(line) > 0)
		{
			tmp = ft_strsplit(line, ' ');
			line_validate(&tmp, 7);
			cam_params(s, tmp);
			view_dir = sub_vec_by_vec(s->cam.lp, s->cam.c);
			s->cam.focal = sqrt(pow(view_dir.x - s->cam.c.x, 2) +
								pow(view_dir.y - s->cam.c.y, 2) +
								pow(view_dir.z - s->cam.c.z, 2));
			normalize_vector(&view_dir);
			cam_vector_compute(s, view_dir);
			++*l;
			clear_tab(tmp);
		}
		free(line);
	}
	body_parse(s, fd, l);
}

void				parse(t_mlx *s, int fd)
{
	int				l;
	char			*line;
	char			**tmp;

	l = 0;
	while (l != 1 && get_next_line(fd, &line) > 0)
	{
		if (line[0] != '#')
		{
			tmp = ft_strsplit(line, '/');
			line_validate(&tmp, 2);
			s->src_len = ft_atoi(tmp[0]);
			s->obj_len = ft_atoi(tmp[1]);
			s->srcs = (t_object *)secure_malloc(
					sizeof(t_object) * (s->src_len + 1));
			s->objects = (t_object *)secure_malloc(
					sizeof(t_object) * (s->obj_len + 1));
			s->all = (t_object **)secure_malloc(
					sizeof(t_object *) * (s->src_len + s->obj_len + 1));
			++l;
			clear_tab(tmp);
		}
		free(line);
	}
	camera_parse(s, fd, &l);
}
