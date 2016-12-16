
#ifndef COLOR_H
# define COLOR_H

typedef struct 		s_color {
	float			r;
	float			g;
	float			b;

}					t_color;

t_color			create_color(char *str);
t_color			mult_color_double(t_color c1, float nbr);
t_color			mult_color(t_color c1, t_color c2);
t_color			add_color(t_color c1, t_color c2);
int 			get_color_value(t_color c);
#endif