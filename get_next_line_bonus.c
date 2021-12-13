/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:40:11 by fleitz            #+#    #+#             */
/*   Updated: 2021/12/13 08:48:34 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

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
		str = ft_strndup(buff, end);
	else
	{
		save2 = ft_strndup(buff, end);
		save = ft_strjoin(str, save2);
		free(str);
		str = ft_strndup(save, (ft_strlen(save) + 1));
		free(save);
		free(save2);
	}
	size = BUFFER_SIZE - end;
	ft_memcpy(buff, &buff[end], size);
	buff[size] = '\0';
	buff[size + 1] = '\0';
	return (str);
}

char	*ft_buffcpy(char *buff, char *str)
{
	char	*save;

	if (str == NULL)
	{
		str = ft_strndup(buff, BUFFER_SIZE);
		return (str);
	}
	save = ft_strjoin(str, buff);
	free(str);
	buff[0] = '\0';
	return (save);
}

int	ft_stop(char *buff, ssize_t rd)
{
	if (rd == 0)
	{
		buff[1] = 1;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = "\0\0";
	char		*str;
	ssize_t		rd;

	str = NULL;
	while (1)
	{
		if (buff[0] == '\0' && buff[1] == 1)
			return (NULL);
		if (ft_strchr(buff, '\n') != NULL)
		{
			str = ft_n_buffcpy(buff, str);
			return (str);
		}
		if (buff[0] != '\0')
			str = ft_buffcpy(buff, str);
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		buff[rd] = '\0';
		if (ft_stop(buff, rd) == 0)
			return (str);
	}		
}
