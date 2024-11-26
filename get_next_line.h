/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:30:17 by carlopez          #+#    #+#             */
/*   Updated: 2024/11/20 11:45:32 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *str2);
char	*ft_strdup(char *str);
char	*ft_fill_remainder(char *initial_buffer, int position);
char	*ft_fill_buffer(char *initial_buffer, int position);
int	check_newline(char *initial_buffer);
void	ft_free(char **str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
#endif
