/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:54:23 by fleitz            #+#    #+#             */
/*   Updated: 2021/12/08 17:45:22 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftgithub/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_n_buffcpy(char *buff, char *str)
{
	size_t	end;
	size_t	size;
	char	*save;
	char	*save2;

	end = 0;
	while (buff[end] != '\0' && buff[end] != '\n')
		end++;
	end++;
	if (str == NULL)
		str = strndup(buff, end);
	else
	{
		save2 = strndup(buff, end);
		save = ft_strjoin(str, save2);
		free(str);
		str = ft_strdup(save);
		free(save);
		free(save2);
	}
	size = BUFFER_SIZE - end;
	ft_memcpy(buff, &buff[end], size);
	buff[size] = '\0';
	return (str);
}

char	*ft_buffcpy(char *buff, char *str)
{
	char	*save;

	if (str == NULL)
	{
		str = ft_strdup(buff);
		return (str);
	}
	save = ft_strjoin(str, buff);
	free(str);
	ft_bzero(buff, (BUFFER_SIZE + 1));
	return (save);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;
	ssize_t		rd;

	str = NULL;
	while (1)
	{
		if (buff[0] == '\0' && buff[1] == 1)
		{
			return (NULL);
		}
		if (buff[0] == '\0')
		{
			rd = read(fd, buff, BUFFER_SIZE);
			if (rd == -1)
				return (NULL);
			if (rd < BUFFER_SIZE)
			{
				if (ft_strchr(buff, '\n') != NULL)
				{
					str = ft_n_buffcpy(buff, str);
					return (str);
				}
				str = ft_buffcpy(buff, str);
				buff[1] = 1;
				return (str);
			}
		}
		if (ft_strchr(buff, '\n') != NULL)
		{
			str = ft_n_buffcpy(buff, str);
			return (str);
		}
		str = ft_buffcpy(buff, str);
		buff[0] = '\0';
	}
	return (NULL);
}
