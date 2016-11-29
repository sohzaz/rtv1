/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 15:11:58 by dbreton           #+#    #+#             */
/*   Updated: 2016/05/23 14:01:45 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO rename file
#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <libft.h>
# include <get_next_line.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "vector.h"
# define WIN_MAX_X 640
# define WIN_MAX_Y 480
# define PTR_MOTION_MASK (1L << 6)
# define MOTION_NOTIFY 6



typedef struct			s_camera{
    int					x;
    int                 y;
    int                 z;
    double              focal;
    float               rot_x;
    float               rot_y;
    float               rot_z;
	double 				ix;
	double 				iy;
	t_vector			lp;
    t_vector			vp;
    t_vector            c;
	t_vector			vix;
	t_vector			viy;
    double              vhh;
	t_vector			vu;
	t_vector			vv;
	double 				aspect;
    double              vhw;
}                       t_camera;
typedef struct			s_object{
    int                 id;
	double 				color;
	int                 x;
	int                 y;
	int                 z;
	char 				type;
	float 				kd;
	float 				ks;
	float 				pr;
	float 				psh;
	float 				IOR;
	float               rot_x;
	float               rot_y;
	float               rot_z;
	int                 radius;
	double				*(*inter)(struct s_object *, t_vector *, t_camera, struct s_object);
	t_vector			(*normal)(t_vector *, struct s_object *);
}                       t_object;
typedef struct			s_mlxdata{
	void				*mlx;
	void				*win;
	void				*img;
	t_camera        	cam;
	long long			zoom;
	int 				type;
	long long			x_start;
	long long			y_start;
	int					max_ite;
	t_object        	*objects;
	t_object        	*sources;
	int             	obj_len;
	int             	src_len;
	int					f_lock;
}						t_mlx;

void					win_init(t_mlx s);
void                    render_pic(t_mlx *s);
void                    parse(t_mlx *s, int fd);
void					put_in_image(t_mlx *s, int x, int y, int color);
int						mouse_zoom_handler(int btn, int x, int y, t_mlx *s);
int						key_win_handler(int key, t_mlx *s);
int						ptr_motion_hook(int x, int y, t_mlx *s);
int	        			expose_hook(t_mlx *s);
void                    get_numbers(t_mlx *s, int x, int y);
void					win_reset(t_mlx *s);
int                     get_inters(t_mlx *s, t_vector *v);
t_object				sphere(char **tmp);
t_object				plane(char **tmp);
t_object				source(char **tmp);

#endif
