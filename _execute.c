#include "shell.h"
/**
 * _execute - execute command
 * @cmd: commad to execute
 * @argv: argument variable
 * Return: -1 on error
 */
int _execute(char **cmd, char **argv, int id)
{
	char *Fcmd;
	pid_t pid;
	int status;

	Fcmd = find_path(cmd[0]);
	if (!Fcmd)
 	{
		error_msg(argv[0], cmd[0], id);
		free_arr(cmd);
		return(127);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(Fcmd, cmd, environ) == -1)
		{
			free(Fcmd), Fcmd = NULL;
			free_arr(cmd);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_arr(cmd);
		free(Fcmd), Fcmd = NULL;
	}
	return(WEXITSTATUS(status));
}
