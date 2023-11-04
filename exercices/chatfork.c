#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;
    int i;

    for (i = 0; i < 4; i++) {
        child_pid = fork();
        if (child_pid == 0) {
            printf("Child %d running...\n", i);;
            exit(10 + i);
        }
    }

    while ((child_pid = wait(&status)) > 0) {
        printf("Child process %d terminated with status: %d\n", child_pid, WEXITSTATUS(status));
    }

    return 0;
}

