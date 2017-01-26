/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 14:42:52 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/20 15:30:26 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <libft.h>
#include <stdio.h>

static void		check_overflow(t_color *c,
		float tmp_r, float tmp_g, float tmp_b)
{
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

	tab = ft_strsplit(str, ',');
	if (tab && tab_len(tab) == 3)
	{
		res.r = ft_atoi(tab[0]) / 255.0f;
		res.g = ft_atoi(tab[1]) / 255.0f;
		res.b = ft_atoi(tab[2]) / 255.0f;
	}
	else
	{
		res.r = 0.0f;
		res.g = 0.0f;
		res.b = 0.0f;
	}
	clear_tab(tab);
	return (res);
}

t_color			mult_color_double(t_color c1, float nbr)
{
	t_color		res;
	float		tmp_r;
	float		tmp_g;
	float		tmp_b;

	tmp_r = c1.r * nbr;
	tmp_g = c1.g * nbr;
	tmp_b = c1.b * nbr;
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
	tmp_g = c1.g * c2.g;
	tmp_b = c1.b * c2.b;
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
	tmp_g = c1.g + c2.g;
	tmp_b = c1.b + c2.b;
	check_overflow(&res, tmp_r, tmp_g, tmp_b);
	return (res);
}
