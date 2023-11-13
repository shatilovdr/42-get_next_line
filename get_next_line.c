/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:39:03 by dshatilo          #+#    #+#             */
/*   Updated: 2023/11/13 17:24:07 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*ft_strjoin(char const *s1, char const *s2, size_t s2_len);

char	*get_next_line(int fd)
{
	static char	*string = 0;
	char		*line;

	if (!string)
	{
		string = (char *)malloc(sizeof(char) * 1);
		if (!string)
			return (0);
		*string = 0;
	}
	if (!string) //prevent attempt to read file after its end.
		return (0);
	string = get_string(string, fd);
	line = ft_getline(&string);

	return (line);
}


char	*get_string(char *s, int fd)
{
	static size_t		bytes_read = 1;
	char				*buffer;
	char				*string;

	string = 0;
	while (!ft_strchr(string, '\n') && bytes_read > 0)
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buffer)
		{
			free(s);
			return (0);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (0);
		string = ft_strjoin(s, buffer, bytes_read);
		if (!string)
			return (0);
	}
	return (string);
}

static char	*ft_strjoin(char const *s1, char const *s2, size_t s2_len)
{
	size_t	newlen;
	size_t	s1_len;
	char	*s;

	s1_len = ft_strlen(s1);
	if ((size_t)(-1) - s1_len < s2_len)
		return (0);
	newlen = s1_len + s2_len + 1;
	s = (char *)malloc(sizeof(char) * newlen);
	if (!s)
	{
		free(s1);
		free(s2);
		return (0);
	}
	s = ft_strncpy(s, (char *)s1, s1_len);
	ft_stnrcpy(s + s1_len, (char *)s2, s2_len);
	s[newlen] = 0;
	free(s1);
	free(s2);
	return (s);
}


char	*ft_getline(char *string);
{
	
}

