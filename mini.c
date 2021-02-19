#include "minishell.h"

void	exec_cmd(char **tab, char **env)
{
	pid_t	pid;
	int		status;

	pid = 0;
	status = 0;
	(void)env;
	if ((pid = fork()) == -1)
		write(1, strerror(errno), ft_strlen(strerror(errno)));
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(tab[0], tab, NULL) == -1)
		{
			write(1, strerror(errno), ft_strlen(strerror(errno)));
			write(1, "\n", 1);
		}
		exit(EXIT_FAILURE);
	}
}

int     main(int argc, char **argv, char **env)
{
	mini_t		a;
	char		*path;

	(void)argc;
	(void)argv;
	a.buffer = NULL;
	a.tab = NULL;
	a.tmp = NULL;
	a.buff = 1;
	a.ret = 1;
	path = get_absolute_path(env);
	printf("path = %s\n", path);
	write(1, "$> ", 3);
	while (a.ret > 0)
	{
		a.len = 0;
		if ((a.fd = open("/dev/stdin", O_RDONLY)) < 0)
			return (write(1, strerror(errno), ft_strlen(strerror(errno))));
		a.ret = get_next_line(a.fd, &a.buffer);
		a.tab = ft_split(a.buffer, ' ');
		if (a.tab[0] == NULL)
			write(1, "Command not found\n", 18);
		else
			exec_cmd(a.tab, env);
		if (!strcmp(a.buffer, "quit"))
			exit (0);
		else
			write(1, "$> ", 3);
		close(a.fd);
		free(a.buffer);
		free_tab(a.tab);
	}
	return (0);
}

