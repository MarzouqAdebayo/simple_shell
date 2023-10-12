#include "shell.h"

/**
 * free2DArray - Free memory allocated for a two-dimensional array of strings.
 * @arr: A pointer to the 2D array of strings.
 *
 * This function deallocates the memory occupied by a two-dimensional array of
 * strings.
 * It first iterates through the rows of the array and frees the memory for
 * each individual
 * string. Afterward, it frees the memory allocated for the array itself.
 *
 * If 'arr' is NULL or the array is empty, the function simply returns without
 * performing any memory deallocation.
 *
 * Parameters:
 *   arr: A pointer to the 2D array of strings to be freed.
 *
 * Return: None.
 */

void free2DArray(char **arr)
{
	int i;

	if (!arr)
		return;
	if (!arr[0])
	{
		free(arr);
		return;
	}

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
