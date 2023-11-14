/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:39:46 by dshatilo          #+#    #+#             */
/*   Updated: 2023/11/14 16:22:52 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //REMOVE ME!!!!
# include <fcntl.h> //REMOVE ME!!!!

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_free(char *s);
char	*add_to_string(char *s, char *buffer, size_t buf_len);
char	*check_string(char *s);

#endif
