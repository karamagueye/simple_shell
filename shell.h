#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* PROTOTYPES */

int len(char *s);
void shell(void);
void get_process(char *command);
void free_2d_array(char **arr);

#endif /* SHELL_H */
