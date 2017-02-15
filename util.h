/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:34:08 by dbreton           #+#    #+#             */
/*   Updated: 2017/01/27 13:34:16 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_UTIL_H
# define RTV1_UTIL_H
# ifndef FLT_EPSILON
#  define FLT_EPSILON 1.19209290E-07F
# endif

int		tab_len(char **tab);
void	clear_tab(char **str);
char	almost_equal_relative(double a, double b);
void	line_validate(char ***tmp, int len);
void	*secure_malloc(unsigned int len);
#endif
