/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:39:50 by dshatilo          #+#    #+#             */
/*   Updated: 2023/11/13 15:56:29 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str);
char			*ft_strncpy(char *dest, char *src, size_t n);


char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i) != 0)
	{
		if (*(s + i) == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char) c == 0)
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*(str + length) != 0)
		length++;
	return (length);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (!src)
	{
		*dest = 0;
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// char	*ft_realloc(char *str, size_t add)
// {
// 	char	*new_str;
// 	size_t	strlen;
// 	size_t	newlen;

// 	strlen = ft_strlen(str);
// 	newlen = -1;
// 	if (newlen - strlen < add)
// 		return (0);
// 	newlen = strlen + add;
// 	new_str = (char *)malloc(sizeof(char) * (newlen + 1));
// 	if (!new_str)
// 		return (0);
// 	new_str[strlen] = 0;
// 	if (!str)
// 		return (new_str);
// 	new_str = ft_strncpy(new_str, str, strlen);
// 	free(str);
// 	return (new_str);
// }







