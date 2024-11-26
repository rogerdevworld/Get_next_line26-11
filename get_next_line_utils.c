/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:47:28 by carlopez          #+#    #+#             */
/*   Updated: 2024/11/20 11:44:42 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	//if (!str)//si le paso algo vacio el valor igual es 0 esto esta demas 
	//	return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*str_cpy;

	if (!str)
		return (NULL);
	str_cpy = malloc(ft_strlen(str) + 1);
	if (!str_cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}

char	*ft_strjoin(char *str, char *str2)
{
	char	*returned_str;
	int	i;
	int	j;

	returned_str = malloc(ft_strlen(str) + ft_strlen(str2) + 1);
	if (!returned_str)
		return (NULL);
	i = 0;
	while (str)// esto es lo mismo(str && str[i] != '\0')
		returned_str[i] = str[i++];
	//ft_free(&str);
	j = 0;
	while (str2)//(str2 && str2[j] != '\0') lo mismo
		returned_str[i++] = str2[j++];
	returned_str[i] = '\0';
	//ft_free(&str2);
	return (returned_str);
}

/* esto pude ser solo una funcion y l hago para eliminar lineas del get_next_line */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
		p[i++] = 0;
}