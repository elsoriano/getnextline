/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:39:43 by rhernand          #+#    #+#             */
/*   Updated: 2024/06/17 21:55:54 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
	int		i;
	char	*buff;
	size_t	bytes_read;

	i = 1;
	
	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);
	if(fd == "STDIN_FILENO")
	bytes_read = read(fd, &buff[0], 1);
	if (! buff[0])
		return(NULL);
	while(buff[i - 1] != '\n')
	{
		bytes_read = read(fd, &buff[i++], 1);
		if (bytes_read == -1)
		{
			free(buff);
			return("");
		}
		if (bytes_read == 0)
		{
			buff[i] = '\0';
			return (buff);
		}
	}
	buff[i - 1] = 'n';
	buff[i] = '\0';
	return (buff);
}
int main(int argc, char **argv)
{
	int	fd;
	int	fd2;
	int	i;
	
	i = 0;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	while (i < 40)
	{
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd2));
		i++;
	}
}