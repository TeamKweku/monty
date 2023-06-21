#include "monty.h"
/**
 * is_string_empty - checks if a string is empty
 * @str: string to check
 * @delim: delimiter string
 * Return: 1 if empty, 0 if not empty
 */
int is_string_empty(char *str, char *delim)
{
	int i, j;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
				break;
		}
		if (!delim[j])
			return (0);
	}
	return (1);
}

/**
 * node_length - returns the number of nodes in a stack
 * @head: pointer to the first node in the stack
 * Return: the length of the stack
 */
size_t node_length(stack_t *head)
{
	int length = 0;

	if (head == NULL)
		return (length);

	while (head != NULL)
	{
		head = head->next;
		length++;
	}

	return (length);
}

/**
 * split_string - splits a string into an array of strings
 * @input_string: string to be splitted into tokens
 * @delimiter: delimiter
 *
 * Return: array of strings
 */
char **split_string(char *input_string, char *delimiter)
{
	char *str_cpy = NULL, *token = NULL, **str_arr = NULL;
	int arr_size = 0, i;

	if (input_string == NULL)
		return (NULL);
	str_cpy = _strdup(input_string);
	if (str_cpy == NULL)
		return (NULL);
	token = strtok(input_string, delimiter);
	while (token)
	{
		token = strtok(NULL, delimiter);
		arr_size++;
	}
	str_arr = malloc(sizeof(char *) * (arr_size + 1));
	if (str_arr == NULL)
		return (NULL);

	token = strtok(str_cpy, delimiter);
	i = 0;
	while (token)
	{
		str_arr[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	str_arr[arr_size] = NULL;
	free(str_cpy);
	return (str_arr);
}


/**
 * tokenizer - function that tokenizes a string
 * @str_ptr: pointer to the string to be tokenized
 * @delim: delimiter string
 * Return: pointer to the token
 */
char *tokenizer(char **str_ptr, const char *delim)
{
	char *token;
	char *next;

	if (str_ptr == NULL || *str_ptr == NULL)
		return (NULL);

	token = *str_ptr;
	next = strstr(token, delim);

	if (next != NULL)
	{
		*next = '\0';
		*str_ptr = (char *)(next + strlen(delim));
	}
	else
		*str_ptr = NULL;

	return (token);
}
