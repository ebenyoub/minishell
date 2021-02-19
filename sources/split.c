#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/minishell.h"


void    pass_space_split(int *i, char sep, char *str)
{
	if (str[*i] == sep)
		while (str[*i] && str[*i] == sep)
			*i += 1;
}

int		count_words(char *str, char sep)
{
	int i;
	int	nb;

	i = 0;
	nb = 0;
	if (str)
	{
		while (str[i])
		{
			pass_space_split(&i, sep, str);
			if (str[i] != sep)
			{
				nb++;
				while (str[i] && str[i] != sep)
					i++;
			}
			else
				pass_space_split(&i, sep, str);
		}
	}
	return (nb);
}

char	**ft_split(char *str, char sep)
{
	char	**cmd;
	int		words;
	int		i;
	int		a;
	int		b;
	int		c;

	i = 0;
	a = 0;
	c = 0;
	if (!str)
		return (NULL);
	words = count_words(str, sep);
	if (!(cmd = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (a < words)
	{
		b = 0;
		c = 0;
		pass_space_split(&i, sep, str);
		while (str[i + b] && str[i + b] != '\n' && str[i + b] != sep)
			b++;
		if (!(cmd[a] = malloc(sizeof(char) * b + 1)))
			return (NULL);
		while (c < b)
			cmd[a][c++] = str[i++];
		cmd[a][c] = '\0';
		a++;
	}
	cmd[a] = NULL;
	return (cmd);
}

void	free_cmd(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		cmd[i] = NULL;
		i++;
	}
	free(cmd);
	cmd = NULL;
}