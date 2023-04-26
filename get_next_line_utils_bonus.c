/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:40:24 by fleitz            #+#    #+#             */
/*   Updated: 2021/12/13 14:38:46 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = (char *) malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, (i + 1));
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	dst2 = (char *) dst;
	src2 = (char *) src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	cmp;

	if (s == NULL)
		return (NULL);
	cmp = 0;
	while (s[cmp])
		cmp++;
	cmp++;
	i = 0;
	while (i < cmp)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}
