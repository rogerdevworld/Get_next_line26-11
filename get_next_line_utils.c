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

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	str_len;
	int	i;
	char	*str_cpy;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	str_cpy = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str_cpy)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
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
	int	len;

	len = ft_strlen(str) + ft_strlen(str2) + 1;
	returned_str = (char *)malloc(len * sizeof(char));
	if (!returned_str)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str && str[i] != '\0')
		{
			returned_str[i] = str[i];
			i++;
		}
		ft_free(&str);
	}
	if (str2)
	{
		j = 0;
		while (str2 && str2[j] != '\0')
			returned_str[i++] = str2[j++];
		returned_str[i] = '\0';
		ft_free(&str2);
	}
	return (returned_str);
}
