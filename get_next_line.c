/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 10:38:52 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/05/20 12:45:01 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*result_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	result_line = ft_calloc(2 + i, sizeof(char));
	if (!result_line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		result_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		result_line[i++] = '\n';
	return (result_line);
}

char	*ft_next_line(char *buffer)
{
	
}

char	*get_next_line(int fd)
{
	
}