//
// Created by Drien BRETON on 1/23/17.
//

#include "fractol.h"
static void			rotate(t_object *obj, char **str)
{
	double 			tmp[2];
	double 			angles[3];

	printf("in:%s||%s||%s\n", str[1], str[2], str[3]);

	angles[0] = ft_atoi(str[1]) * M_PI / 180.0f;
	angles[1] = ft_atoi(str[2]) * M_PI / 180.0f;
	angles[2] = ft_atoi(str[3]) * M_PI / 180.0f;
	printf("angles: %f||%f||%f\n", angles[0], angles[1], angles[2]);
	tmp[0] = obj->dir.x;
	tmp[1] = obj->dir.y;
	obj->dir.x = tmp[0] * cos(angles[0]) - tmp[1] * sin(angles[0]);
	obj->dir.y = tmp[0] * sin(angles[0]) + tmp[1] * cos(angles[0]);
	tmp[0] = obj->dir.x;
	tmp[1] = obj->dir.z;
	obj->dir.x = tmp[0] * cos(angles[1]) - tmp[1] * sin(angles[1]);
	obj->dir.z = tmp[0] * sin(angles[1]) + tmp[1] * cos(angles[1]);
	tmp[0] = obj->dir.y;
	tmp[1] = obj->dir.z;
	obj->dir.y = tmp[0] * cos(angles[2]) - tmp[1] * sin(angles[2]);
	obj->dir.z = tmp[0] * sin(angles[2]) + tmp[1] * cos(angles[2]);
	//printf("%f||%f||%f\n", obj->dir.x, obj->dir.y, obj->dir.z);

}
static void			translate(t_object *obj, char **str)
{
	obj->x += ft_atoi(str[1]);
	obj->y += ft_atoi(str[2]);
	obj->z += ft_atoi(str[3]);
}

static void			apply_transform(t_object *obj, char **str )
{
	printf("%s,%s,%s,%s,%s\n", str[0], str[1], str[2], str[3], str[4]);
	if (ft_strcmp(str[4], "translation") == 0)
	{
		printf("before trans: %f||%f||%f\n", obj->x, obj->y, obj->z);
		translate(obj, str);
		printf("after: %f||%f||%f\n", obj->x, obj->y, obj->z);
	}
	else if (ft_strcmp(str[4], "rotation") == 0 )
	{
		printf("before rot: %f||%f||%f\n", obj->dir.x, obj->dir.y, obj->dir.z);
		rotate(obj, str);
		printf("after: %f||%f||%f\n", obj->dir.x, obj->dir.y, obj->dir.z);
	}
}

void				transform_parse(t_mlx *s, int fd, int *l) {
	char			*line;
	char			**tmp;
	int 			o;
	int 			tmp_id;

	while (get_next_line(fd, &line) > 0)
		if (line[0] != '#')
		{
			o = 0;
			tmp = ft_strsplit(line, ' ');
			++*l;
			tmp_id = ft_atoi(tmp[0]);
			while (s->all[o])
			{
				if (s->all[o]->id == tmp_id) {

					apply_transform(s->all[o], tmp);

				}

				++o;
			}
		}
}