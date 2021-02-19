/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:09:53 by ebenyoub          #+#    #+#             */
/*   Updated: 2021/02/19 14:52:04 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

char    *get_env(char **env)
{
	char    *path;
	int     i;

	i = 0;

	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
		{
			path = ft_strdup(env[i] + 5);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*file_existance(char **split_path, mini_t *a)
{
	int i;
	int n;
	char	*bin;
	struct stat sb;

	i = 0;
	n = 0;
	bin = NULL;
	while (split_path[i])
	{
		bin = NULL;
		n = ft_strlen(split_path[i]) + 1 + ft_strlen(a->cmd[0]) + 10;
		if (!(bin  = ft_calloc(n, sizeof(char))))
			return (NULL);
		ft_strcat(bin, split_path[i]);
		ft_strcat(bin, "/");
		ft_strcat(bin, a->cmd[0]);
		if (!(stat(bin, &sb)))
			return (bin);
		free(bin);
		bin = NULL;
		i++;
	}
	return (NULL);
}

int     get_absolute_path(char **env, mini_t *a)
{
	char    *path;
	char    *bin;
	char    **path_split;

	bin = NULL;
	path_split = NULL;
	if (!(path = get_env(env)))
		path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (a->cmd[0][0] != '/' && ft_strncmp(a->cmd[0], "./", 2) != 0)
	{
		if (!(path_split = ft_split(path, ':')))
			return (0);
		free(path);
		path = NULL;
		if (!(bin = file_existance(path_split, a)))
			return (0);
		free_cmd(path_split);
		free(a->cmd[0]);
		a->cmd[0] = bin;
	}
	else
	{
		free(path);
		path = NULL;
	}
	return (1);
}