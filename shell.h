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


#endif /* SHELL_H */
