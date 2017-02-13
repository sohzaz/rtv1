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

#include "rtv1.h"

static int			is_closest(double *d, double *res)
{
	int				i;
	double			d_init;

	i = 1;
	d_init = *d;
	while (i <= (int)res[0])
	{
		*d = (res[i] > 0 && *d > res[i]) ? res[i] : *d;
		++i;
	}
	return (d_init != *d);
}

static t_vector		create_vector(t_mlx *s, int i, int j)
{
	t_vector		v;
	t_vector		vpp;

	vpp = add_vector(s->cam.vp, add_vector(
			mult_vec_double(s->cam.vix, (double)i),
			mult_vec_double(s->cam.viy, (double)j)));
	v = sub_vec_by_vec(vpp, s->cam.c);
	normalize_vector(&v);
	return (v);
}

t_color				get_inters(t_mlx *s, t_vector *v)
{
	int				i;
	double			d;
	double			*res;
	t_object		*closest;

	d = 99999999.9f;
	i = 0;
	closest = NULL;
	while (i < (s->obj_len))
	{
		res = s->objects[i].inter(s->objects[i], v, s->cam.c);
		if (is_closest(&d, res) == 1)
			closest = &s->objects[i];
		free(res);
		i++;
	}
	return ((closest && d < 99999999.9f) ?
			get_color(s, closest,
					add_vector(s->cam.c, mult_vec_double(*v, d))) :
			create_color("0,0,0"));
}

void				*cast_ray(void *data)
{
	t_color			tmp;
	t_vector		v;
	t_thread		th;
	pthread_mutex_t	mutex;

	pthread_mutex_lock(&mutex);
	th = *(t_thread *)data;
	pthread_mutex_unlock(&mutex);
	th.i = 0;
	while (th.i < (WIN_MAX_X + 1))
	{
		v = create_vector(th.s, th.i, th.j);
		tmp = get_inters(th.s, &v);
		put_in_image(th.s, th.i, th.j, tmp);
		++th.i;
	}
	return (NULL);
}

void				render_pic(t_mlx *s)
{
	int				i;
	int				j;
	pthread_t		th[WIN_MAX_Y];
	t_thread		data;

	j = 0;
	data.s = s;
	i = WIN_MAX_Y;
	while (j < (WIN_MAX_Y + 1))
	{
		data.j = j;
		pthread_create(&th[j], NULL, &cast_ray, (void *)&data);
		pthread_detach(th[j]);
		++j;
	}
}
