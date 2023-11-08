#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

extern char **environ;

/* PROTOTYPES */

int len(char *s);
void shell(char *name);
void get_process(char **command, char *name);
char **args(char *command, char *delim);
int list_words(char *command, char *delim);

#endif /* SHELL_H */
