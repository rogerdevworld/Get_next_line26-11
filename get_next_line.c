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

char *get_next_line(int fd)
{
    ssize_t bytes_read;
    char *initial_buffer;
    static char *remainder;
    char *final_buffer;
    int newline_pos;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    initial_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!initial_buffer)
        return NULL;

    final_buffer = ft_strdup(remainder ? remainder : "");
    remainder = NULL;

    bytes_read = 1;  // Inicializamos en 1 para entrar al bucle

    while (bytes_read > 0)
    {
        if (check_newline(final_buffer) != -1)
            break;

        bytes_read = read(fd, initial_buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;

        initial_buffer[bytes_read] = '\0';  // Aseguramos que el buffer esté terminado en NULL
        final_buffer = ft_strjoin(final_buffer, initial_buffer);
    }

    free(initial_buffer);

    newline_pos = check_newline(final_buffer);
    if (newline_pos != -1)
    {
        remainder = ft_strdup(final_buffer + newline_pos + 1);
        if (!remainder)
        {
            free(final_buffer);
            return NULL;
        }
        final_buffer[newline_pos + 1] = '\0';
    }

    if (bytes_read == 0 && !*final_buffer)
    {
        free(final_buffer);
        return NULL;
    }

    return final_buffer;
}

int check_newline(char *buffer)
{
    int i = 0;

    while (buffer[i])
    {
        if (buffer[i] == '\n')
            return i;
        i++;
    }

    return -1;
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