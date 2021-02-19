#include "minishell.h"

char    *get_absolute_path(char **env)
{
    char    *path;
    int     i;

    i = 0;
    while (env[i])
    {
        if (env[i][0] == 'P' && env[i][1] == 'A'
        && env[i][2] == 'T' && env[i][3] == 'H')
        {
            path = ft_strdup(env[i] + 5);
            return (path);
        }
        i++;
    }
    return (NULL);
}