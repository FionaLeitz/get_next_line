/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:28:31 by fleitz            #+#    #+#             */
/*   Updated: 2021/12/07 17:10:58 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftgithub/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
/*
char	*get_next_line(int fd)
{
	static char	*buff;
	char		*str;
	size_t		end;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (buff != NULL)
	{
		if (strchr(buff, '\n') != NULL)
		{
			end = 0;
			while (buff[end] != '\n')
				end++;
			str = strndup(buff, (end + 1));
			buff = &buff[end + 1];
			return (str);
		}
		strcat(str, buff);
	}
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (buff == NULL)
	{
		free(str);
		return (0);
	}
	while (read(fd, buff, (BUFFER_SIZE) > 0))
	{
		if (strchr(buff, '\n') != NULL)
		{
			end = 0;
			while (buff[end] != '\n')
				end++;
			strncat(str, buff, (end + 1));
			buff = &buff[end + 1];
			return (str);
		}
		strcat(str, buff);
	}
	free(buff);
	return (NULL);
}*/

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;
	char		*save;
	char		*save2;
	size_t		end;
	ssize_t		rd;

	str = NULL;
	if (buff[0] != '\0')
	{
		if (strchr(buff, '\n') != NULL)
		{
			end = 0;
			while (buff[end] != '\n')
				end++;
			if (str == NULL)
				str = strndup(buff, (end + 1));
			else
			{
				save = ft_strjoin(str, buff);
				save[ft_strlen(str) + end + 1] = '\0';
				free(str);
			memcpy(buff, &buff[end + 1], (ft_strlen(&buff[end + 1]) + 1));
				return (save);
			}
			memcpy(buff, &buff[end + 1], (ft_strlen(&buff[end + 1]) + 1));
			return (str);
		}
		str = strdup(buff);
	}
	while ((rd = read(fd, buff, BUFFER_SIZE)) == BUFFER_SIZE)
	{
		if (strchr(buff, '\n') != NULL)
		{
			end = 0;
			while (buff[end] != '\n')
				end++;
			if (str == NULL)
				str = strndup(buff, (end + 1));
			else
			{
				save2 = malloc(sizeof(char) * BUFFER_SIZE + 1);
				save2 = strndup(buff, end + 1);
				save = ft_strjoin(str, save2);
				free(save2);
				free(str);
				memcpy(buff, &buff[end + 1], (ft_strlen(&buff[end + 1]) + 1));
				return (save);
			}
			memcpy(buff, &buff[end + 1], (ft_strlen(&buff[end + 1]) + 1));
			return (str);
		}
		if (str == NULL)
			str = strdup(buff);
		else
		{
			save = ft_strjoin(str, buff);
			free(str);
			str = strdup(save);
			free(save);
		}
	}
	if (rd > 0)
	{
		buff[rd] = '\0';
		save = ft_strjoin(str, buff);
		free(str);
		return (save);
	}
	return (NULL);
}
