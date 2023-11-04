#include "shell.h"
/**
 * free_2d_array - frees a 2d array, null-terminated
 * @arr : pointer to a 2d array
 */
void free_2d_array(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
