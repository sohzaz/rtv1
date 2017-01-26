//
// Created by Drien BRETON on 1/3/17.
//
#include "fractol.h"

int 		tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

void			clear_tab(char **str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

t_object		create_new_src()
{
	t_object	res;

	res.x = 0;
	res.y = 0;
	res.z = 0;
	res.color.r  = NAN;
	res.color.g  = 0;
	res.color.b  = 0;
	return (res);
}
