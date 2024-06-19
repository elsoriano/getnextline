/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:39:43 by rhernand          #+#    #+#             */
/*   Updated: 2024/06/19 09:52:52 by rhernand         ###   ########.fr       */
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

char	*ft_str_build(int fd, char *buff)
{
	int		i;
	char	*str;
	int		bytes_read;

	i = 1;
	if (!buff)
		return (NULL);
	while (buff[i - 1] != '\n')
	{
		bytes_read = read(fd, &buff[i++], 1);
		if (bytes_read == -1)
			return (ft_free(buff));
	}
	buff[i - 1] = 'n';
	buff[i] = '\0';
	str = ft_strdup((const char *)buff);
	if (!str)
		return (ft_free(buff));
	free(buff);
	return (str);
}

char	*ft_read_fd(int fd)
{
	size_t	bytes_read;
	char	*buff;

	buff = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = read(fd, &buff[0], 1);
	if (bytes_read <= 0)
		return (ft_free(buff));
	return (ft_str_build(fd, buff));
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
