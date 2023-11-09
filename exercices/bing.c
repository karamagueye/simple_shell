#include "main.h"
/**
 *
 */
int _which(char *filename)
{
    char **pathname = NULL, *path_copy;
    char *path;
    int i, pathname_length;
    char *s;
    struct stat st;

    s = getenv("PATH");
    pathname = args(s, ":");
    for (i = 0; pathname[i] != NULL; i++)
    {
        path_copy = strdup(pathname[i]);
        if (path_copy == NULL)
        {
            perror("strdup");
            exit(7);
        }
        pathname_length = strlen(pathname[i]) + strlen(filename);
        path = malloc(sizeof(char) * (pathname_length + 2));
        if (path == NULL)
        {
            perror("malloc");
            free(path_copy);
            exit(8);
        }
        strcpy(path, path_copy);
        strcat(path, "/");
        strcat(path, filename);
        if (stat(path, &st) == 0)
        {
            printf("found");
            free(path_copy);
            free(path);
            return (0);
        }
        free(path_copy);
        free(path);
    }
    printf("not found");
    return (1);
}
/**
 *
 */
int main(int ac, char **av)
{
        (void)ac;
        _which(av[1]);
        return (0);
}
