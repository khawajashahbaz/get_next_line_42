/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 10:38:47 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/05/21 11:53:49 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n != 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total;

	total = count * size;
	if (size && (total / size != count))
		return (NULL);
	p = (void *)malloc(total);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, total);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	if (ch == '\0')
	{
		i = ft_strlen(s);
		return ((char *)s + i ++);
	}
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *str1, char const *str2)
{
	int		i;
	int		j;
	char	*str3;

	i = 0;
	j = 0;
	if (!str1)
		str1 = ft_calloc(1, 1);
	if (!str1 || !str2)
		return (NULL);
	str3 = (char *)malloc(
			(ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str3)
	{
		free(str1);
		return (NULL);
	}
	while (str1[i] != '\0')
		str3[j++] = str1[i++];
	i = 0;
	while (str2[i] != '\0')
		str3[j++] = str2[i++];
	str3[j] = '\0';
	free(str1);
	return (str3);
}
