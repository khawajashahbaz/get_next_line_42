/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 10:38:52 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/05/21 13:39:11 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*result_line;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
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
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_read_file(int fd, char *result)
{
	int		data_read;
	char	*buffer;
	char	*tmp;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	data_read = 1;
	while (data_read > 0)
	{
		data_read = read(fd, buffer, BUFFER_SIZE);
		if (data_read == -1)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		buffer[data_read] = '\0';
		tmp = result;
		result = ft_strjoin(tmp, buffer);
		if (ft_strchr(result, '\n'))
			break ;
	}
	free(buffer);
	if (data_read == 0 && (!result || !result[0]))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file (fd, buffer);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

// int	main(void)
// {
// 	int			fd;
// 	char		*line;
// 	static char	buffer[BUFFER_SIZE];
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("FIle couldn't be opened \n");
// 	}
// 	else
// 	{
// 		printf("File is opened \n");
// 	}
// 	// read(fd, buffer, sizeof(buffer) - 1);
// 	// printf("1st call: %s \n", buffer);
// 	// read(fd, buffer, sizeof(buffer) - 1);
// 	// printf("2nd call: %s \n", buffer);
// 	// read(fd, buffer, sizeof(buffer) - 1);
// 	// printf("3rd call: %s \n", buffer);
// 	// read(fd, buffer, sizeof(buffer) - 1);
// 	// printf("3rd call: %s \n", buffer);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line start : %s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
