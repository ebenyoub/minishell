#include "../includes/minishell.h"

void	exec_cmd(char **cmd, char **env)
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
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			write(1, strerror(errno), ft_strlen(strerror(errno)));
			write(1, "\n", 1);
		}
		exit(EXIT_FAILURE);
	}
}

int 	shell_loop(char **env, mini_t *a)
{
	while (a->ret > 0)
	{
		a->len = 0;
		if ((a->fd = open("/dev/stdin", O_RDONLY)) < 0)
			return (0);
		a->ret = get_next_line(a->fd, &a->buffer);
		a->cmd = ft_split(a->buffer, ' ');
		if (!(get_absolute_path(env, a)))
			return (0);
		if (a->cmd[0][0] == '\0')
			write(1, "Command not found\n", 18);
		else if (!strcmp(a->buffer, "quit"))
			exit (EXIT_SUCCESS);	
		else
			exec_cmd(a->cmd, env);
		write(1, "$> ", 3);
		close(a->fd);
		free(a->buffer);
		free_cmd(a->cmd);
	}
	return (1);
}

int     main(int argc, char **argv, char **env)
{
	mini_t		a;

	if (argc != 1)
		return (-1);
	(void)argv;
	a.buffer = NULL;
	a.cmd = NULL;
	a.tmp = NULL;
	a.buff = 1;
	a.ret = 1;
	write(1, "$> ", 3);
	if (!(shell_loop(env, &a)))
		return (write(1, strerror(errno), ft_strlen(strerror(errno))));
	return (0);
}

