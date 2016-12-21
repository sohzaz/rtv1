#include "color.h"
#include <libft.h>
#include <stdio.h>

static void		check_overflow(t_color *c, float tmp_r, float tmp_g, float tmp_b)
{
	printf("pre-overflow: %f, %f ,%f\n", tmp_r, tmp_g, tmp_b);
	if (tmp_r > 1.0f)
		c->r = 1.0f;
	else
		c->r = tmp_r;
	if (tmp_g > 1.0f)
		c->g = 1.0f;
	else
		c->g = tmp_g;
	if (tmp_b > 1.0f)
		c->b = 1.0f;
	else
		c->b = tmp_b;
}
t_color			create_color(char *str)
{
	char		**tab;
	t_color		res;

	printf("color str = %s\n", str);
	tab = ft_strsplit(str, ',');
	if (tab)
	{
		res.r = ft_atoi(tab[0]) / 255.0f;
		res.g = ft_atoi(tab[1]) / 255.0f;
		res.b = ft_atoi(tab[2]) / 255.0f;
		printf("in scalar: {%f, %f, %f}\n", res.r,
		res.g,
		res.b);
	} else {
		res.r = 0.0f;
		res.g = 0.0f;
		res.b = 0.0f;
	}
	return (res);
}
t_color			mult_color_double(t_color c1, float nbr)
{
	t_color		res;
	float		tmp_r;
	float		tmp_g;
	float		tmp_b;

	tmp_r = c1.r * nbr;
	tmp_g =	c1.g * nbr;
	tmp_b =	c1.b * nbr;
	printf("mult double\n");
	check_overflow(&res, tmp_r, tmp_g, tmp_b);
	return (res);

}
t_color			mult_color(t_color c1, t_color c2)
{
	t_color		res;
	float		tmp_r;
	float		tmp_g;
	float		tmp_b;

	tmp_r = c1.r * c2.r;
	tmp_g =	c1.g * c2.g;
	tmp_b =	c1.b * c2.b;
	printf("mult\n");
	check_overflow(&res, tmp_r, tmp_g, tmp_b);
	return (res);
}
t_color			add_color(t_color c1, t_color c2)
{
	t_color		res;
	float		tmp_r;
	float		tmp_g;
	float		tmp_b;

	tmp_r = c1.r + c2.r;
	tmp_g =	c1.g + c2.g;
	tmp_b =	c1.b + c2.b;
	printf("add: c1:{r:%f, g:%f, b:%f}\nc2:{r:%f, g:%f, b:%f}\n", c1.r, c1.g, c1.b, c2.r, c2.g, c2.b);
	check_overflow(&res, tmp_r, tmp_g, tmp_b);
	return (res);
}