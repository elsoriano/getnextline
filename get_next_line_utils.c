/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:40:08 by rhernand          #+#    #+#             */
/*   Updated: 2024/06/19 11:03:12 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	j;
	size_t	i;
	char	*buff;

	if (!s1 && !s2)
		return (NULL);
	j = 0;
	buff = (char *) malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		buff[i] = s1[i];
		i++;
	}
	while (s2[j])
		buff[i++] = s2[j++];
	buff[i] = '\0';
	return (buff);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)(s + i)) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	buff = malloc(count * size);
	if (buff == NULL)
		return (NULL);
	ft_bzero(buff, count * size);
	return (buff);
}

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c % 256)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c % 256)
		return ((char *) &s[i]);
	return (NULL);
}
