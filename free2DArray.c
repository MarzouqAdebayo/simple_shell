#include "shell.h"

/**
 * free2DArray - frees a 2D array
 * @arr: pointer to the 2D array
 *
 * Return: has no return value
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
