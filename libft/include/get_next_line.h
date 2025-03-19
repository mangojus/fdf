/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:16:10 by rshin             #+#    #+#             */
/*   Updated: 2025/02/03 20:02:41 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

// GET_NEXT_LINE

char	*get_next_line(int fd);

// UTILS

void	gnl_bzero(void *s, size_t n);
int		gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
void	*gnl_memmove(void *dest, const void *src, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);

#endif
