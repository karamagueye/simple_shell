#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/* PROTOTYPES */

int len(char *s);
char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strspn(char *s, char *accept);
int _atoi(char *s);

void shell(char *name, char **env, int exit_status);
void _getline(char *name, char **env, int exit_status);
void handle_built_ins(char **lineptr, char **env, int exit_status);
void get_process(char **command, char *name, char **env);
char **args(char *command, char *delim);
int list_words(char *command, char *delim);
char *_which(char *filename);
char *_strchr(char *s, char c);
int _execvp(char *filename, char **arguments);
void exec_command(char **command, char **arguments, char *name);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
char *check_path(char *filename);

#endif /* SHELL_H */
