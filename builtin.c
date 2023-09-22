#include "shell.h"

/**
 * is_builtin - check if commad is builtin
 * @cmd: cmd to check
 * Return: 1 if is builtin, 0 otherwise
 */
int is_builtin(char *cmd)
{
	char *builtin[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
	int i;

	for (i = 0; builtin[i]; i++)
	{
		if (_strcmp(cmd, builtin[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handl_built - execute builtin commads
 * @cmd: commad to execute its first token
 * @argv: argument in main
 * @status: of command
 * @id: index
 */
void handl_built(char **cmd, char **argv, int *status, int id)
{

	if (_strcmp(cmd[0], "exit") == 0)
		shell_exit(cmd, argv, status, id);
	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, status);
}

/**
 * shell_exit - exit from the shell
 * @cmd: commad to free
 * @status: status of last command
 */
void shell_exit(char **cmd,char **argv, int *status, int id)
{
	int exit_val = *status;
	char *index, err_msg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_integer(cmd[1]))
			exit_val = _atoi(cmd[1]);
		else
		{
			index = _itoa(id);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free_arr(cmd);
			*status = 2;
			return;
		}
	}
	free_arr(cmd);
	exit(exit_val);
}

/**
 * print_env - print all arg in environ
 * @cmd: commad env
 * @status: of cmd
 */
void print_env(char **cmd, int *status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arr(cmd);
	*status = 0;
}
