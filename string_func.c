#include "monty.h"
/**
  * _strlen - function that returns the len of a string
  * @s: string to be checked
  *
  * Return: an int value for len of string
  */
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

/**
  * _strcmp - compares two strings
  * @str1: the first string
  * @str2: the second string
  *
  * Return: (0) if found, or -ve or +ve value if otherwise
  */
int _strcmp(char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

/**
  * _is_digit - function that checks if string consists 
  * of only digits
  * @str: string to be checked
  *
  * Return: 1 - chars are digit or 0 - otherwise
  */
int _is_digit(char *str)
{
	int len = 0;
	int negative = 0;

	while(str[len])
		len++;
	if (str[0] == '-')
		negative++;
	while (negative < len)
	{
		if (str[negative] >= '0' &&
				str[negative] <= '9')
		{
			/* nothing happens */
		}
		else
		{
			return (0);
		}

		negative++;
	}

	return (1);
}

/**
  * _strcpy - copies the string src to dest
  * @dest: pointer to destination copied str
  * @src: pointer to string to be copied
  *
  * Return: Pointer to destination string
  */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
  * strdup
  */

char *_strdup(char *str)
{
	size_t len = _strlen(str);
	char *dup = malloc((len + 1) * sizeof(char));

	if (!dup)
		return (NULL);
	_strcpy(dup, str);

	return (dup);
}
