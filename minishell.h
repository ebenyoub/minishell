#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

# define BUFF 10

typedef struct		mini_s
{
	char	**tab;
	char    *buffer;
	char	*tmp;
	int     buff;
	int		ret;
	int		len;
	int		fd;
	char	*path;
	char	*bin;
	char	**path_split;
}					mini_t;

typedef struct      gnl_s
{
	char            *clean;
	char            buffer[BUFF + 1];
	int             len;
	int             a;
}                   gnl_t;

int     get_next_line(int fd, char **line);
int     ft_strlen(char *str);
int     ft_strchr(char c, char *str);
char    *ft_strndup(int size, char *str);
char    *ft_strdup(char *str);
char    *ft_strjoin(char *s1, char *s2);
void    afree(char **str);
int     pass_space(char *str);
void	free_tab(char **tab);
char	**ft_split(char *str, char sep);
char    *get_absolute_path(char **env);

#endif