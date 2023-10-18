#include "shell.h"

void dummy2(void);

/**
 * iswhitespace - Checks if a character is a whitespace character.
 * @s: The character to be checked.
 *
 * Return: 1 if 's' is a whitespace character, 0 otherwise.
 *
 * This function determines whether the input character 's' is a whitespace
 * character.
 * It returns 1 if 's' is a whitespace character, and 0
 * otherwise.
 */

int iswhitespace(char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || s == '\r')
		return (1);
	return (0);
}

/**
 * collapse_whitespace - Collapses multiple whitespace characters into a
 * single space.
 * @old: The input string containing whitespace to be collapsed.
 *
 * Return: A pointer to the newly allocated string with collapsed whitespace,
 * or NULL on failure.
 *
 * This function takes an input string 'old' and creates a new string 'new'
 * where multiple consecutive
 * whitespace characters (spaces, tabs, newlines, etc.) in 'old' are collapsed
 * into a single space ' ' and leading spaces are removed.
 * The 'new' string is dynamically allocated and must be freed by the caller
 * when no longer needed.
 * If 'old' is NULL or memory allocation fails, the function returns NULL.
 */

char *collapse_whitespace(char *old)
{
	int i = 0, j = 0, last_char_is_whitespace = 0, leading_whitespace = 1;
	int len = _strlen(old);
	char *new = NULL;

	if (old == NULL)
		return (NULL);

	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);

	while (old[i])
	{
		if (iswhitespace(old[i]))
		{
			if (!last_char_is_whitespace && !leading_whitespace)
			{
				new[j] = ' ';
				last_char_is_whitespace = 1;
				j++;
			}
		}
		else
		{
			leading_whitespace = 0;
			new[j] = old[i];
			last_char_is_whitespace = 0;
			j++;
		}
		i++;
	}

	new[j] = '\0';
	return (new);
}

/**
 * split_str - Split a string into an array of substrings using a delimiter.
 * @src: The input string to be split.
 * @delimiter: The character used to split the string.
 *
 * Return: A dynamically allocated array of strings containing the substrings
 *         extracted from the input string `src`. The last element of the
 *         array is NULL.
 *         If memory allocation fails or the input is empty, the function
 *         returns NULL.
 *
 * Description: This function takes an input string `src` and a delimiter
 * character
 * `delimiter`. It splits the input string into multiple substrings using the
 * delimiter
 * character. The resulting substrings are stored in a dynamically allocated
 * array,
 * and the last element of the array is set to NULL to indicate the end. If
 * memory allocation fails or the input string is empty, the function returns
 * NULL.
 */
char **split_str(char *src, const char delimiter)
{
	int len, i, j, words_no = 0, word_start, word_index, word_length;
	char **dest_arr = NULL;

	if (!src)
		return (NULL);

	len = _strlen(src);
	if (len == 0)
		return (NULL);

	words_no = 1;
	for (i = 0; i < len; i++)
	{
		if (src[i] == delimiter && src[i + 1] && src[i + 1] != delimiter)
			words_no++;
	}
	dest_arr = malloc((words_no + 1) * sizeof(char *));
	if (!dest_arr)
		return (NULL);
	word_start = 0;
	word_index = 0;
	for (i = 0; i <= len; i++)
	{
		if (src[i] == delimiter || src[i] == '\0')
		{
			word_length = i - word_start;
			if (word_length < 1)
				continue;
			dest_arr[word_index] = malloc((word_length + 1) * sizeof(char));
			if (!(dest_arr[word_index]))
			{
				for (j = 0; j < word_index; j++)
					free(dest_arr[j]);
				free(dest_arr);
				return (NULL);
			}
			_strncpy(dest_arr[word_index], src + word_start, word_length);
			(dest_arr)[word_index][word_length] = '\0';
			word_start = i + 1;
			word_index++;
		}
	}
	dest_arr[words_no] = NULL;

	return (dest_arr);
}

/**
 * dummy2 - To trick betty
 *
 * Return: has no return value
 */
void dummy2(void)
{
}
