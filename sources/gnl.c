/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:45:28 by ebenyoub          #+#    #+#             */
/*   Updated: 2021/02/19 13:22:30 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		next_line(char **tmp, char **line, gnl_t *g)
{
	if (ft_strchr('\n', *tmp) == 0)
	{
		*line = ft_strndup(ft_strlen(*tmp), *tmp);
		afree(&*tmp);
		return (0);
	}
	if ((g->a = ft_strchr('\n', *tmp)) > 0)
	{
		*line = ft_strndup(g->a, *tmp);
		g->clean = ft_strndup(ft_strlen(*tmp) - g->a, *tmp + g->a + 1);
		afree(&*tmp);
		*tmp = g->clean;
		return (1);
	}
	return (-1);
}

int     get_next_line(int fd, char **line)
{
	gnl_t			g;
	static char		*tmp;

	if (!line || fd < 0 || BUFF < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (tmp == NULL)
		tmp = ft_strndup(0, "");
	while (ft_strchr('\n', tmp) == 0 && (g.len = read(fd, g.buffer, BUFF)) > 0)
	{
		g.buffer[g.len] = '\0';
		tmp = ft_strjoin(tmp, g.buffer);
	}
	return (next_line(&tmp, line, &g));
}
