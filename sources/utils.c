#include "../includes/minishell.h"

int     ft_strlen(char *str)
{
    int i = 0;
    if (str)
    {
        while(str[i])
            i++;
        return (i);
    }
    return (0);
}

int     ft_strchr(char c, char *str)
{
    int i = -1;
    if (str)
         while (str[++i])
            if (str[i] == c)
                return (i);
    return(0);
}

char    *ft_strdup(char *str)
{
    int     i = 0;
    char    *cpy = malloc(sizeof(char) * ft_strlen(str) + 1);
    while (str[i])
    {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}

char    *ft_strndup(int size, char *str)
{
    int     i = 0;
    char    *cpy = malloc(sizeof(char) * (size + 1));
    while (str[i] && i < size)
    {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int     i;
    int     a;
    char    *cpy;
    i = 0;
    a = 0;
    if (!(cpy = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
        return (NULL);
    while (s1[i])
    {
        cpy[i] = s1[i];
        i++;
    }
    while(s2[a])
    {
        cpy[i] = s2[a];
        i++;
        a++;
    }
    cpy[i] = '\0';
    return (cpy);
}

void    afree(char **str)
{
    if (*str)
        free(*str);
    *str = NULL;
}