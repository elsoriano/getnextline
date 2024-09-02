/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:47:39 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/02 14:45:34 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_update_stack(char *stack)
{
	char	*new_stack;
	char	*aux;
	size_t	i;

	i = 0;
	new_stack = ft_strchr(stack, '\n');
	if (!new_stack)
		return (free(stack), stack = NULL, NULL);
	new_stack++;
	aux = malloc((ft_strlen(new_stack) + 1) * sizeof(char));
	if (!aux)
		return (free(stack), stack = NULL, NULL);
	while (new_stack[i])
	{
		aux[i] = new_stack[i];
		i++;
	}
	aux[i] = '\0';
	free(stack);
	return (aux);
}

char	*ft_create_line(char *stack)
{
	size_t	pos;
	char	*line;

	pos = 0;
	while (stack[pos] && stack[pos] != '\n')
		pos++;
	if (stack[pos] == '\n')
		pos++;
	line = malloc((pos + 1) * sizeof (char));
	if (!line)
		return (NULL);
	pos = 0;
	while (stack[pos] && stack[pos] != '\n')
	{
		line[pos] = stack[pos];
		pos++;
	}
	if (line[pos] == '\n')
		line[pos++] = '\n';
	line[pos] = '\0';
	return (line);
}

char	*ft_join(char *str1, char *str2)
{
	char	*aux;

	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	if (!str1)
		return (NULL);
	aux = ft_strjoin(str1, str2);
	free(str1);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		*line;
	char		tmp[BUFFER_SIZE + 1];
	int			read_bytes;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_strchr(tmp, '\n')))
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(stack), stack = NULL, NULL);
		tmp[read_bytes] = '\0';
		stack = ft_join(stack, tmp);
		if (!stack)
			return (NULL);
	}
	line = ft_create_line(stack);
	stack = ft_update_stack(stack);
	return (line);
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