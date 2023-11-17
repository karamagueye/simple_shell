#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* PROTOTYPES */

int len(char *s);
void shell(void);
void get_process(char *command);

#endif /* SHELL_H */
