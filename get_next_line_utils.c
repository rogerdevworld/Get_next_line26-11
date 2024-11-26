#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

char *ft_strdup(char *str)
{
    int i = 0;
    char *str_cpy;

    if (!str)
        return NULL;

    str_cpy = malloc(ft_strlen(str) + 1);
    if (!str_cpy)
        return NULL;

    while (str[i])
    {
        str_cpy[i] = str[i];
        i++;
    }
    str_cpy[i] = '\0';

    return str_cpy;
}

char *ft_strjoin(char *str, char *str2)
{
    char *returned_str;
    int i = 0;
    int j = 0;

    if (!str)
        return ft_strdup(str2);
    if (!str2)
        return ft_strdup(str);

    returned_str = malloc(ft_strlen(str) + ft_strlen(str2) + 1);
    if (!returned_str)
        return NULL;

    while (str[i])
    {
        returned_str[i] = str[i];
        i++;
    }

    while (str2[j])
    {
        returned_str[i] = str2[j];
        i++;
        j++;
    }

    returned_str[i] = '\0';

    return returned_str;
}

void *ft_calloc(size_t nmemb, size_t size)
{
    void *s;

    if (size == 0 || nmemb == 0)
        return malloc(0);

    s = malloc(nmemb * size);
    if (!s)
        return NULL;

    ft_bzero(s, nmemb * size);

    return s;
}

void ft_bzero(void *s, size_t n)
{
    unsigned char *p = (unsigned char *)s;
    size_t i = 0;

    while (i < n)
        p[i++] = 0;
}
