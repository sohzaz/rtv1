//
// Created by Drien BRETON on 12/16/16.
//
#include <stdio.h>
#include "color.h"

int main(void)
{
	t_color c;
	t_color c1;
	t_color c2;

	c.r = 0.30;
	c.g = 0.59;
	c.b = 0.25;
	c1.r = 0.0;
	c1.g = 0.9;
	c1.b = 0.25;
	c2.r = 0.10;
	c2.g = 0.49;
	c2.b = 0.65;
	printf("%d\n", get_color_value(mult_color(c1, c2)));
	printf("%d\n", get_color_value(c));

	return (0);
}