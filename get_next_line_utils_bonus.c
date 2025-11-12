/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamal <mgamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:14:40 by mgamal            #+#    #+#             */
/*   Updated: 2025/11/12 14:14:41 by mgamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*concat(char const *s1, char const *s2, char *ptr)
{
	size_t	i;
	size_t	u;

	i = 0;
	u = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[u])
	{
		ptr[i] = s2[u];
		i++;
		u++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	size_t	ptr_len;
	char	*ptr;

	if (!s2)
		return (NULL);
	if (!s1)
		a = 0;
	else
		a = ft_strlen(s1);
	b = ft_strlen(s2);
	ptr_len = a + b;
	ptr = malloc(ptr_len + 1);
	if (!ptr)
		return (NULL);
	if (!s1)
	{
		ptr[0] = '\0';
		return (concat(ptr, (char *)s2, ptr));
	}
	return (concat((char *)s1, (char *)s2, ptr));
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*extracted_line(char *arr)
{
	int		i;
	char	*line;

	if (!arr[0])
		return (NULL);
	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	if (arr[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (arr[i] && arr[i] != '\n')
	{
		line[i] = arr[i];
		i++;
	}
	if (arr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
