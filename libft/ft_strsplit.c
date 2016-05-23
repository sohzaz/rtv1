/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:12:02 by dbreton           #+#    #+#             */
/*   Updated: 2015/04/15 08:47:45 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
static int      count_words(char const *s, char c)
{
    int         words;
    size_t      i;

    words = 0;
    i = 0;
    while (s[i] != 0)
    {
        if (s[i] != c && ((s[i + 1] != 0 && s[i + 1] == c) || s[i + 1] == 0)) 
            ++words;
        ++i;

    }   
    return (words);
}
static void  do_split(char const *s, char c, char ***result)
{
    int j;
    int i;

    i = 0;
    while (*s)
    {
        while (c == *s && *s)
            ++s;
        j = 0;
        while (c != *(s + j) && *(s + j))
            ++j;
        if (j)
        {
            (*result)[i] = malloc(sizeof(char) * (j + 1));
            if (!(*result)[i])
                return ;
            j = 0;
            while (c != *s && *s)
                (*result)[i][j++] = *s++;
            (*result)[i++][j] = '\0';
        }
    }
    (*result)[i] = NULL;
}

char				**ft_strsplit(char const *s, char c)
{
    char **result;

    if (!s)
        return (NULL);
    result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!result)
        return (NULL);
    do_split(s, c, &result);
    return (result);

}
