#include "shell.h"

/**
 * free_2d_array - Free memory allocated for a two-dimensional array of strings.
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

void free_2d_array(char **arr)
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

/**
 * _realloc - Reallocate memory for a previously allocated block.
 *
 * @ptr: A pointer to the previously allocated memory block.
 * @old_size: The old size (in bytes) for the memory block.
 * @new_size: The new size (in bytes) for the memory block.
 *
 * Return: If successful, a pointer to the newly allocated memory block
 * NULL on failure.
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *new = NULL, *cast_ptr = ptr;
	size_t i, max = new_size > old_size ? old_size : new_size;

	if (!ptr && !new_size)
		return (NULL);
	if (!ptr && new_size)
	{
		new = malloc(new_size);
		if (!new)
			return (NULL);
		return (new);
	}
	if (ptr && !new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	for (i = 0; i < max; i++)
		*(new + i) = *(cast_ptr + i);
	free(ptr);

	return (new);
}
