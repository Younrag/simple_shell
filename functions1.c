#include "shell.h"
/**
 * free_arr - free array 2D
 * @arr: array to free
 */
void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr), arr = NULL;
}
/**
 * error_msg - print error
 * @name: firt print
 * @cmd: second print
 * @id: index
 */
void error_msg(char *name, char *cmd, int id)
{
	char *index, errmsg[] = ": not found\n";

	index = _itoa(id);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, errmsg, _strlen(errmsg));

	free(index);
}
/**
 * _itoa - int to string
 * @n: int to transform
 * Return: caracter integer
 */
char *_itoa(int n)
{
	char buf[20];
	int i = 0;

	if (n == 0)
		buf[i++] = '0';
	else
	{
		while (n > 0)
		{
			buf[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buf[i] = '\0';
	rev_string(buf, i);

	return (_strdup(buf));
}
/**
 * rev_string - reverse string
 * @str: string to rev
 * @len: lenght
 */
void rev_string(char *str, int len)
{
	char tmp;
	int init = 0;
	int end = len - 1;

	while (init < end)
	{
		tmp = str[init];
		str[init] = str[end];
		str[end] = tmp;
		init++;
		end--;
	}
}
