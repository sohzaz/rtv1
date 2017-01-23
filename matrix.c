//
// Created by Drien BRETON on 1/11/17.
//

#include "matrix.h"

t_matrix		new_matrix(int w, int h)
{
	int			i;
	int			j;
	t_matrix	m;

	m.cont = (double **)malloc(sizeof(double *) * h);
	m.heigth = h;
	m.width = w;
	i = 0;
	while (i < h)
	{
		j = 0;
		m.cont[i] = (double *)malloc(sizeof(double) * w);
		while (j < w)
		{
			m.cont[i][j] = 0.0f;
			++j;
		}
		++i;
	}
	return(m);
}

void			add_matrix_double(t_matrix *m, double nbr)
{
	int 		i;
	int 		j;

	i = 0;
	while (i < m->heigth)
	{
		j = 0;
		while (j < m->width)
		{
			m->cont[i][j] += nbr;
			++j;
		}
		++i;
	}
}

void 			destroy_matrix(t_matrix *m)
{
	int 		i;

	i = 0;
	while (i < m->heigth)
	{
		free(m->cont[i]);
		++i;
	}
	free(m->cont);
}