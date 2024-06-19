/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:39:43 by rhernand          #+#    #+#             */
/*   Updated: 2024/06/19 13:03:10 by rhernand         ###   ########.fr       */
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
	
	if (!str)
		return (ft_free(str));
	offset = ft_strchr(str, '\n') + 1;
	if (!offset)
		return (str);
	updstr = malloc((ft_strlen(str) - offset) * sizeof(char) + 1);
	if (!updstr)
		ft_free(str);
	while (str[i])
	{
		updstr[i] = str[offset + i];
		i++;
	}
	updstr[i] = '\0';
	free(str);
	return (updstr);
}

char	*ft_line_build(char *str)
{
	size_t	len;
	char	*line;

	len = ft_strchr(str, '\n');
	if (len == 0)
		len = ft_strlen(str);
	line = malloc(len * sizeof(char) + 1);
	if (!line)
		return (NULL);
	if (!ft_strlcpy(line, str, len - 1))
		return (ft_free(line));
	line[len - 1] = 'n';
	line[len] = '\0';
	return (line);
}

char	*ft_read_fd(int fd)
{
	size_t		bytes_read;
	char		buff[BUFFER_SIZE + 1];
	static char	*str;
	char		*line;

	str = NULL;
	bytes_read = BUFFER_SIZE;
	printf("%ld", bytes_read);
	while (!ft_strchr(buff, '\n') || bytes_read < BUFFER_SIZE)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(str));
		buff[bytes_read] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (ft_free(str));
	}
	printf("%s", str);
	line = ft_line_build(str);
	str = ft_str_update(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buff;

	if (!fd || fd <= 0 || BUFFER_SIZE <= 0)
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
	
	i = 0;
	fd = open(argv[1], O_RDONLY);
	printf("hola\n");
	// fd2 = open(argv[2], O_RDONLY);
	while (i < 1)
	{
		str = get_next_line(fd);
		if (!str)
			return (1);
		printf("%s\n", str);
		free(str);
		// printf("%s\n", get_next_line(fd2));
		i++;
	}
}
