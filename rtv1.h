/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:57:17 by dbreton           #+#    #+#             */
/*   Updated: 2017/02/02 16:57:20 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <libft.h>
# include <get_next_line.h>
# include "color.h"
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "vector.h"
# include "util.h"
# include <SDL2/SDL.h>

# define WIN_MAX_X 1920
# define WIN_MAX_Y 1080

struct s_mlxdata;

typedef struct		s_camera {
	int				x;
	int				y;
	int				z;
	int				fov;
	double			focal;
	double			ix;
	double			iy;
	t_vector		lp;
	t_vector		vp;
	t_vector		c;
	t_vector		vix;
	t_vector		viy;
	double			vhh;
	t_vector		vu;
	t_vector		vv;
	double			aspect;
	double			vhw;
}					t_camera;
typedef struct		s_object {
	int				id;
	t_color			color;
	t_vector		dir;
	float			x;
	float			y;
	float			z;
	char			type;
	float			kd;
	float			ks;
	float			psh;
	double			radius;
	float			intensity;
	double			*(*inter)(struct s_object, t_vector *, t_vector);
	t_vector		(*normal)(t_vector *, struct s_object *);
	double			(*get_color)(struct s_mlxdata *,
								struct s_object *, t_vector);
	t_color			(*diffuse)(struct s_object *,
								struct s_object *, t_vector *);
    t_color         (*specular)(struct s_object *,
                                struct s_object *, t_vector *, t_vector *);
}					t_object;

typedef struct		s_mlxdata {
	SDL_Renderer	*ren;
	SDL_Window		*win;
	SDL_Texture		*img;
	t_camera		cam;
	int				type;
	t_object		*objects;
	t_object		*srcs;
	t_object		**all;
	int				obj_len;
	int				src_len;
	int				need_refresh;
	Uint32			*pixels;
	int				pitch;
	Uint32			format;
	int				wh[2];
	char			need_reload;
}					t_mlx;
void				win_init(t_mlx s);
void				render_pic(t_mlx *s);
void				parse(t_mlx *s, int fd);
void				put_in_image(t_mlx *s, int x, int y, t_color color);
void				expose_hook(t_mlx *s);
t_color				get_inters(t_mlx *s, t_vector *v);
t_object			sphere(char **tmp);
t_object			plane(char **tmp);
t_object			source(char **tmp);
t_object			cylinder(char **tmp);
t_object			cone(char **tmp);
void				ft_exit(const int code, const char *msg);
void				cam_params(t_mlx *s, char **tmp);
t_color				get_color(t_mlx *s, t_object *self, t_vector inter);
t_object			get_obj_type(char **tmp);
void				transform_parse(t_mlx *s, int fd, int *l);
#endif
