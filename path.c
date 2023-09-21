#include "shell.h"
/**
 * find_path - get the path
 * @cmd: commad to check
 * Return: full command
 */
char *find_path(char *cmd)
{
	char *path, *Fcmd, *dir;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	dir = strtok(path, ":");
	while (dir)
	{
		Fcmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (Fcmd)
		{
			_strcpy(Fcmd, dir);
			_strcat(Fcmd, "/");
			_strcat(Fcmd, cmd);
			if (stat(Fcmd, &st) == 0)
			{
				free(path);
				return (Fcmd);
			}
			free(Fcmd), Fcmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
