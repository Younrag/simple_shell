#include "shell.h"

/**
 * read_l - read line function
 * Description: read line input
 * Return: line pointer
 */
char *read_l(void)
{
	char *line = NULL;
	size_t l = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &l, stdin);
	if (n == -1)
	{
		free(line); line = NULL;
		return(NULL);
	}

	return(line);
}
