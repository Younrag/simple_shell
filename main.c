#include "shell.h"
/**
 * main - Simple_shell main function
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0, id = 0;
	(void) argc;

	while (1)
	{
		line = read_l();
		if (line == NULL) /* EOF */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return(status);
		}
		id++;

		cmd = token_l(line);
		if (cmd == NULL)
			continue;

		status =  _execute(cmd, argv, id);
	}
}
