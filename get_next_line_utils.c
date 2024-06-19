/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:40:08 by rhernand          #+#    #+#             */
/*   Updated: 2024/06/19 12:48:46 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	j;
	size_t	i;
	char	*buff;

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

size_t	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c % 256)
			return (i);
		i++;
	}
	if (s[i] == c % 256)
		return (i);
	return (0);
}

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (dstsize != 0 && i < dstsize - 1 && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	if (i < dstsize)
		dest[i] = '\0';
	while (src[i])
		++i;
	return (i);
}