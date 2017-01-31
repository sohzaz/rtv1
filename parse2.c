/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:21:07 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:22:27 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			rotate(t_object *obj, char **str)
{
	double				tmp[2];
	double				angles[3];

	angles[0] = ft_atoi(str[1]) * M_PI / 180.0f;
	angles[1] = ft_atoi(str[2]) * M_PI / 180.0f;
	angles[2] = ft_atoi(str[3]) * M_PI / 180.0f;
	tmp[0] = obj->dir.x;
	tmp[1] = obj->dir.y;
	obj->dir.x = tmp[0] * cos(angles[2]) - tmp[1] * sin(angles[2]);
	obj->dir.y = tmp[0] * sin(angles[2]) + tmp[1] * cos(angles[2]);
	tmp[0] = obj->dir.x;
	tmp[1] = obj->dir.z;
	obj->dir.x = tmp[0] * cos(angles[1]) - tmp[1] * sin(angles[1]);
	obj->dir.z = tmp[0] * sin(angles[1]) + tmp[1] * cos(angles[1]);
	tmp[0] = obj->dir.y;
	tmp[1] = obj->dir.z;
	obj->dir.y = tmp[0] * cos(angles[0]) - tmp[1] * sin(angles[0]);
	obj->dir.z = tmp[0] * sin(angles[0]) + tmp[1] * cos(angles[0]);
}

static void			translate(t_object *obj, char **str)
{
	obj->x += ft_atoi(str[1]);
	obj->y += ft_atoi(str[2]);
	obj->z += ft_atoi(str[3]);
}

static void			apply_transform(t_object *obj, char **str)
{
	if (ft_strcmp(str[4], "translation") == 0)
		translate(obj, str);
	else if (ft_strcmp(str[4], "rotation") == 0)
		rotate(obj, str);
}

void				cam_params(t_mlx *s, char **tmp)
{
	s->cam.c.x = ft_atoi(tmp[0]);
	s->cam.c.y = ft_atoi(tmp[1]);
	s->cam.c.z = ft_atoi(tmp[2]);
	s->cam.lp.x = ft_atoi(tmp[4]);
	s->cam.lp.y = ft_atoi(tmp[5]);
	s->cam.lp.z = ft_atoi(tmp[6]);
	s->cam.fov = ft_atoi(tmp[3]);
}

void				transform_parse(t_mlx *s, int fd, int *l)
{
	char			*line;
	char			**tmp;
	int				tmp_int[2];

	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '#')
		{
			tmp_int[0] = 0;
			tmp = ft_strsplit(line, ' ');
			++*l;
			if (tab_len(tmp) != 5)
				ft_exit(2, "file content mismatch\n");
			tmp_int[1] = ft_atoi(tmp[0]);
			while (s->all[tmp_int[0]])
			{
				if (s->all[tmp_int[0]]->id == tmp_int[1])
					apply_transform(s->all[tmp_int[0]], tmp);
				++tmp_int[0];
			}
			clear_tab(tmp);
		}
		free(line);
	}
	free(line);
}
