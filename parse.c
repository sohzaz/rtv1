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
static void		body_parse(t_mlx *s, int fd, int *l)
{
	char		*line;
	char		**tmp;
	int			tot_len;
	int			o;

	tot_len = s->obj_len + s->src_len;
	o = 0;
	while (*l < tot_len && get_next_line(fd, &line) > 0 )
		if (line[0] != '#')
		{
            write(2, line, 256);
            write(2, "/n", 1);
			tmp = ft_strsplit(line, ' ');
			++*l;
			write(2, "C",1);
			if (tmp[0][0] == '0' && o < s->obj_len)
			{
				s->objects[o] = sphere(tmp);
                s->objects[o].inter(NULL, NULL);
				++o;
				printf("%d\n", o);
			}
            s->objects[o - 1].inter(NULL, NULL);
		}
	printf("%d\n", *l);
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
            write(2, tmp[0], 256);
            write(2, "/n", 1);
            write(2, tmp[1], 256);
            write(2, "/n", 1);
            write(2, tmp[2], 256);
            write(2, "/n", 1);
            write(2, tmp[3], 256);
            write(2, "/n", 1);
            write(2, tmp[4], 256);
            write(2, "/n", 1);
            write(2, tmp[5], 256);
            write(2, "/n", 1);
            write(2, tmp[6], 256);
            write(2, "/n", 1);
            ++*l;
			free(line);
		}
	printf("%d\n", s->cam.rot_y);
	body_parse(s, fd, l);
}

void            parse(t_mlx *s, int fd) {
	int         l;
	char        *line;
	char        **tmp;
	write(1, "C", 1);
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
			printf("%s\n", line);
			free(line);
		}
	camera_parse(s, fd, &l);
}
