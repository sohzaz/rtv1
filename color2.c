#include "color.h"
#include <stdio.h>
int 			get_color_value(t_color c)
{
	int			res;

	//res = 0;
	res = (unsigned char)(c.r * 255) & 0xFF;
	res += ((unsigned char)(c.g * 255) & 0x00FF) << 8;
	res += ((unsigned char)(c.b * 255) & 0x0000FF) << 16;
	printf("color: {%f, %f, %f}\ncomputed color: %d\n", c.r, c.g, c.b, res);
	return (res);
}