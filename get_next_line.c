/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:39:03 by dshatilo          #+#    #+#             */
/*   Updated: 2023/11/14 18:48:52 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_string(char *s, char *buffer, int fd, ssize_t bytes);

char	*get_line(char **str);

char	*dealloc(char *s, size_t start);

char	*get_next_line(int fd)
{
	static char	*string = 0;
	char		*buffer;
	char		*line;

	if (fd < 0)
		return (0);
	buffer = 0;
	string = get_string(string, buffer, fd, 1);
	if (!string)
		return (0);
	line = get_line(&string);
	return (line);
}

char	*get_string(char *s, char *buffer, int fd, ssize_t bytes)
{
	s = check_string(s);
	if (!s)
		return (0);
	while ((s && !ft_strchr(s, '\n')) && bytes != 0)
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buffer)
			return (ft_free(s));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(s);
			return (ft_free(buffer));
		}
		if (!bytes)
		{
			free(buffer);
			return (s);
		}
		s = add_to_string(s, buffer, bytes);
		free (buffer);
	}
	return (s);
}

char	*get_line(char **str)
{
	char	*line;
	size_t	line_len;
	char	*s;

	s = *str;
	line_len = 0;
	while (s[line_len] != 0 && s[line_len] != '\n')
		line_len++;
	if (s[line_len] == '\n')
		line_len++;
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (ft_free(s));
	line[line_len] = 0;
	ft_strncpy(line, s, line_len);
	*str = dealloc(s, line_len);
	if (!s)
		return (0);
	return (line);
}

char	*dealloc(char *s, size_t start)
{
	char	*new_s;
	size_t	s_len;
	size_t	n_len;

	s_len = 0;
	while (s[s_len] != 0)
		s_len++;
	n_len = s_len - start;
	new_s = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!new_s)
		return (ft_free(s));
	ft_strncpy(new_s, s + start, n_len);
	new_s[n_len] = 0;
	free(s);
	return (new_s);
}
