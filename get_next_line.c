/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:30:53 by carlopez          #+#    #+#             */
/*   Updated: 2024/11/26 11:59:27 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line (int fd)
{
	ssize_t	bytes_read;
	char	*initial_buffer = NULL;
	static char	*remainder;
	int	newline_position;
	char	*final_buffer = NULL;

	
	if (fd < 0 || BUFFER_SIZE <= 0)//solo por reducir lineas 
		return (NULL);
	initial_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!initial_buffer)
		return (NULL);
	bytes_read = read(fd, initial_buffer, BUFFER_SIZE);
	//initial_buffer[bytes_read] = '\0'; esta line no es necesaria con calloc
	if (bytes_read <= 0)
	{
		//final_buffer = ft_strjoin(remainder, NULL);
		//remainder = NULL;
		//ft_free(initial_buffer);
		free(initial_buffer);
		return (NULL);
	}
	//else if (bytes_read == 0 && !remainder)
	//{
	//	ft_free(&initial_buffer);
	//	return (NULL);
	//}
	//final_buffer = ft_strjoin(remainder, initial_buffer);//(initial_buffer, NULL);
	if (remainder)
	{
		final_buffer = ft_strjoin(remainder, "");
		remainder = NULL;
	}
	else
		final_buffer = ft_strjoin(initial_buffer, "");
	while (bytes_read == BUFFER_SIZE && (check_newline(final_buffer) == -1))
	{
		bytes_read = read(fd, initial_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		initial_buffer[bytes_read] = '\0';
		final_buffer = ft_strjoin(final_buffer, initial_buffer);
	}
	newline_position = check_newline(final_buffer);
	if (newline_position > -1 && newline_position < (ft_strlen(final_buffer) - 1))
	{
		remainder = ft_fill_remainder(final_buffer, newline_position);
		if (!remainder)
			return (NULL);
		final_buffer = ft_fill_buffer(final_buffer, newline_position);
	}
	return (final_buffer);
}

char	*ft_fill_buffer(char *initial_buffer, int position)
{
	char	*final_buffer;
	int	i;

	if (!initial_buffer || position < 0)
		return (NULL);
    int len = ft_strlen(initial_buffer);
    if (position >= len)
        return (NULL);
	final_buffer = malloc((position + 2) * sizeof(char));
	if (!final_buffer)
		return (NULL);
	i = 0;
	while (i <= position)
	{
		final_buffer[i] = initial_buffer[i];
		i++;
	}
	final_buffer[i] = '\0';
	return (final_buffer);
}

char	*ft_fill_remainder(char *initial_buffer, int position)
{
	char	*remainder;
	int	i;
	int	len;

	len = ft_strlen(initial_buffer) - position;// - 1
	remainder = malloc((len) * sizeof(char));
	if (!remainder)
		return (NULL);
	i = 0;
	while (i < len)
		remainder[i++] = initial_buffer[++position];
	remainder[i] = '\0';
	return (remainder);
}

int	check_newline(char *initial_buffer)
{
	int	i;

	i = -1;
	while (initial_buffer[++i])
	{
		if (initial_buffer[i] == '\n')
			return (i);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	int i = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line %i:%s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
}