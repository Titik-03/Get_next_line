/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamal <mgamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:02 by mgamal            #+#    #+#             */
/*   Updated: 2025/11/12 14:18:10 by mgamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*updated(char *arr)
{
	int		i;
	char	*left;
	int		total_lengh;
	int		j;

	i = 0;
	if (!arr && arr[i] == '\0')
		return (NULL);
	while (arr[i] && arr[i] != '\n')
		i++;
	if (!arr[i])
		return (NULL);
	i++;
	total_lengh = ft_strlen(arr);
	left = malloc(total_lengh - i + 1);
	if (!left)
		return (NULL);
	j = 0;
	while (arr[i])
		left[j++] = arr[i++];
	left[j] = '\0';
	return (left);
}

char	*read_write(int fd, char *buffer, char *left)
{
	char	*tmp;
	int		b_r;

	b_r = read(fd, buffer, BUFFER_SIZE);
	while (b_r > 0)
	{
		buffer[b_r] = '\0';
		tmp = ft_strjoin(left, buffer);
		free(left);
		left = tmp;
		if (ft_strchr(left, '\n'))
			break ;
		b_r = read(fd, buffer, BUFFER_SIZE);
	}
	if (b_r < 0)
	{
		free(left);
		return (NULL);
	}
	return (left);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*left[1024];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	left[fd] = read_write(fd, buffer, left[fd]);
	free(buffer);
	if (!left[fd])
		return (NULL);
	line = extracted_line(left[fd]);
	tmp = updated(left[fd]);
	free(left[fd]);
	left[fd] = tmp;
	return (line);
}
