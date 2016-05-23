/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:41:30 by dbreton           #+#    #+#             */
/*   Updated: 2014/12/11 14:25:47 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

int			ft_memcmp(void *s1, void *s2, size_t len);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putstr(char const *s);
size_t		ft_strlen(char const *s);
char		*ft_strdup(char const *s1);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, void const *src, size_t n);
void		*ft_memccpy(void *dst, void const *src, int c, size_t n);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strcat(char *s1, char const *s2);
char		*ft_strncat(char *s1, char const *s2, size_t n);
char		*ft_strcpy(char *dst, char const *src);
char		*ft_strncpy(char *dst, char const *src, size_t n);
int			ft_atoi(char const *str);
int			ft_strcmp(char const *s1, char const *s2);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
char		*ft_strstr(char const *s1, char const *s2);
char		*ft_strnstr(char const *s1, char const *s2, size_t n);
void		*ft_memmove(void *dst, void const *src, size_t len);
size_t		ft_strlcat(char *dst, char const *src, size_t size);
char		*ft_strchr(char const *s, int c);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_putendl(char const *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_striter(char *s, void (*f)(char *));
char		*ft_strrchr(char const *s, int c);
int			ft_strequ(char const *s1, char const *s2);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_itoa(int n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
