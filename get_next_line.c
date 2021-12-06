/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:28:31 by fleitz            #+#    #+#             */
/*   Updated: 2021/12/06 17:59:48 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
/*
char	*get_next_line(int fd)
{
	char	*str;
	char	*save;
	char	*buf;
	size_t	end;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	end = 0;
	str = malloc(sizeof(char));
	if (str == NULL)
	{
		free(buf);
		return (0);
	}
	while (read(fd, buf, (BUFFER_SIZE - 1)) != 0)
	{
		if (strchr(buf, '\n') != NULL)
		{
			while (buf[end] != '\n')
				end++;
			strncat(str, buf, (end + 1));
			save
			free(buf);
			return (str);
		}
		strcat(str, buf);
	}
	free(buf);
	return (str);
}
*/

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*str;
	char		*save;
	size_t		end;

	str2 = malloc(sizeof(char) * BUFFER_SIZE);
	if (str2 == NULL)
		return (NULL);
	str2[0] = '\0';
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
	while (read(fd, buff, (BUFFER_SIZE - 1) > 0))
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
}
