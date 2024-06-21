/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:40:29 by rhernand          #+#    #+#             */
/*   Updated: 2024/06/21 18:25:20 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>


char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, char *src, size_t dstsize);

#endif