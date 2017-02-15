/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:52:11 by dbreton           #+#    #+#             */
/*   Updated: 2015/10/15 11:29:02 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char	*resize(char *str, size_t len)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_strnew(len);
	if (new_str)
	{
		while (str[i] != '\0')
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = '\0';
		ft_strclr(str);
		free(str);
		return (new_str);
	}
	return (str);
}

static char	*linecpy(char *buff, int index)
{
	int		j;
	char	*new_line;

	j = 0;
	new_line = NULL;
	if (buff && *buff)
	{
		new_line = (char *)malloc(index + 1);
		if (new_line)
		{
			while (j < index)
			{
				new_line[j] = buff[j];
				j++;
			}
			new_line[j] = '\0';
		}
	}
	else
	{
		new_line = (char *)malloc(sizeof(char));
		new_line[0] = 0;
	}
	return (new_line);
}

static char	*get_line(char *buff, char **line, char *temp)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = NULL;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] != '\0')
	{
		new_str = ft_strnew(ft_strlen(buff) - i + 1);
		*line = linecpy(buff, i);
		i++;
		while (buff[i] != '\0')
			new_str[j++] = buff[i++];
		new_str[j] = '\0';
	}
	else
		*line = linecpy(buff, i + 1);
	free(buff);
	free(temp);
	return (new_str);
}

int			get_next_line(int const fd, char **line)
{
	int			i;
	static char	*buff;
	char		*temp;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	i = 1;
	if (!buff)
		buff = ft_strnew(BUFF_SIZE + 1);
	temp = (char *)malloc(BUFF_SIZE + 1);
	if (buff && temp)
	{
		while (i > 0 && ft_strchr(buff, '\n') == NULL)
			if ((i = read(fd, temp, BUFF_SIZE)) > 0)
			{
				temp[i] = '\0';
				buff = resize(buff, ft_strlen(buff) + i + 1);
				buff = ft_strcat(buff, temp);
			}
		buff = get_line(buff, line, temp);
		if (*line[0] != 0 && i >= 0)
			i = (i == 0 && buff && buff[0]) ? 0 : 1;
	}
	return (i);
}
