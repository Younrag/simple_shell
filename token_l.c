#include "shell.h"
/**
 * token_l - Divide line to tokens for each delim
 * @line: the desired line
 * Return: tokens
 */
char **token_l(char *line)
{
	char *token = NULL;
	char *tmp = NULL;
	char **cmd = NULL;
	int count = 0, i = 0;

	if (line == NULL)
		return(NULL);
	tmp = _strdup(line);
	token = strtok(tmp, " \t\n");
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL; 
		return(NULL);
	}

	while(token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(tmp), tmp = NULL;

	cmd = malloc(sizeof(char *) * (count + 1));
	if (cmd == NULL)
	{
		free(line), line = NULL;
		return(NULL);
	}

	token = strtok(line, " \t\n");
	while(token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	
	return(cmd);
}
