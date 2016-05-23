/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 12:45:34 by dbreton           #+#    #+#             */
/*   Updated: 2016/05/16 15:50:02 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void    camera_parse(t_mlx *s, int fd, int *l)
{
    char        *line;
    char        **tmp;

    while (*l != 2 && get_next_line(fd, &line) > 0)
        if (line[0] != '#')
        {
            tmp = ft_stsplit(line, ' ');
        }
    printf("%s\n", line);
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
        }
    camera_parse(s, fd, &l);
}
