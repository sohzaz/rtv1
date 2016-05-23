/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 12:45:34 by dbreton           #+#    #+#             */
/*   Updated: 2016/05/23 13:41:57 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void		body_parse(t_mlx *s, int fd, int *l)
{
	char		*line;
	char		**tmp;

	(void)s;

	while (get_next_line(fd, &line) > 0)
		if (line[0] != '#')
		{
			tmp = ft_strsplit(line,  ' ');
			++*l;
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
			free(line);
        }
    printf("%d\n", s->cam.rot_y);
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
            s->sources = (t_object *)malloc(sizeof(t_object) * s->src_len);
            s->objects = (t_object *)malloc(sizeof(t_object) * s->obj_len);
            ++l;
            printf("%s\n", line);
			free(line);
        }
    camera_parse(s, fd, &l);
}
