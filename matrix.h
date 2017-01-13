//
// Created by Drien BRETON on 1/11/17.
//

#ifndef RTV1_MATRIX_H
# define RTV1_MATRIX_H
# include <stdlib.h>

typedef struct s_matrix {
	int			width;
	int			heigth;
	double 		**cont;

}			t_matrix;

t_matrix	new_matrix(int w, int h);
void		add_matrix_double(t_matrix *m, double nbr);
void 		destroy_matrix(t_matrix *m);

#endif
