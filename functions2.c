#include "shell.h"
/**
 * is_integer - check if string is a number positive
 * @s: string to check
 * Return: 1 success, 0 otherwise.
 */
int is_integer(char *s)
{
	int i;

	if (!s)
		 return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
