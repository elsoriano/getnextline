/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:39:43 by rhernand          #+#    #+#             */
/*   Updated: 2024/06/24 12:18:43 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_free(char *buff)
{
	free(buff);
	return (NULL);
}

char *ft_str_update(char *str)
{
	char	*updstr;
	size_t	offset;
	size_t	i;
	
	i = 0;
	if (!str)
		return (ft_free(str));
	offset = ft_strchr(str, '\n');
	if (str[offset] == '\n')
		offset++;
	// printf("str = %s\n", str);
	// printf("offset %li\n", offset);
	if (!offset)
		return (str);
	updstr = malloc((ft_strlen(str) - offset) * sizeof(char) + 1);
	if (!updstr)
		ft_free(str);
	while (str[offset + i])
	{
		updstr[i] = str[offset + i];
		i++;
	}
	updstr[i] = '\0';
	free(str);
	// printf("updated str = %s\n", updstr);
	return (updstr);
}

char	*ft_line_build(char *str)
{
	size_t	len;
	char	*line;

	len = ft_strchr(str, '\n');
	if (str[len] == '\n')
		len ++;
	// printf("len = %li\n", len);
	if (len == 0)
		len = ft_strlen(str);
	line = malloc(len * sizeof(char) + 1);
	if (!line)
		return (NULL);
	if (!ft_strlcpy(line, str, len))
		return (ft_free(line));
	line[len] = '\0';
	return (line);
}

char	*ft_read_fd(int fd)
{
	int			bytes_read;
	char		buff[BUFFER_SIZE + 1];
	static char	*str = NULL;
	char		*line;

	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		// printf("find break = %li\n", ft_strchr(buff, '\n'));
		// printf("bytes read = %i\n", bytes_read);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		// printf("buff = %s\n", buff);
		if (bytes_read < 0)
			return (ft_free(str));
		buff[bytes_read] = '\0';
		str = ft_strjoin(str, buff);
		// printf("str after join = %s\n", str);
		if (!str)
			return (ft_free(str));
	}
	// printf("str after all iterations = %s\n", str);
	line = ft_line_build(str);
	// printf("line = %s\n", line);
	str = ft_str_update(str);
	// printf("str after update = %s\n", str);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buff;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read_fd(fd);
	if (!buff)
		return (ft_free(buff));
	return (buff);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;
	
	if (argc > 2)
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	printf("fd gen = %i\n", fd);
	printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
	// fd2 = open(argv[2], O_RDONLY);
	while (i < 20)
	{
		str = get_next_line(fd);
		if (!str)
			return (1);
		printf("Final Result = %s\n", str);
		free(str);
		i++;
	}
}
