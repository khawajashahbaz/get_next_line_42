/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 10:38:56 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/05/20 12:33:47 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *str1, char const *str2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
char	*ft_get_line(char *buffer);
char	*ft_next_line(char *buffer);

#endif