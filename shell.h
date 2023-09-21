#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

char *read_l(void);
char **token_l(char *line);
int _execute(char **cmd, char **argv, int id);

char *_getenv(char *var);
char *find_path(char *cmd);


char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

void free_arr(char **arr);
void error_msg(char *name, char *cmd, int id);
char *_itoa(int n);
void rev_string(char *str, int len);

#endif
