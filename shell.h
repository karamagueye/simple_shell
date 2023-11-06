#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

/* PROTOTYPES */

int len(char *s);
void shell(char *name);
void get_process(char *command, char *name);
void free_2d_array(char **arr);
int check(char *command);
void handle_args(char *command, char *name);
char **get_args(char *command);

#endif /* SHELL_H */
