#include "shell.h"

/**
 * custom_strcmp - compares two strings
 * @str1: first string to be compared
 * @str2: second string to be compared
 *
 * Return: Returns the difference between the strings
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0, diff;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
		i++;

	diff = (*(str1 + i) - *(str2 + i));

	return (diff);
}

/**
 * custom_strlen - returns the length of a string
 * @str: string passed
 *
 * Return: Returns the length of the string passed
 */
int _strlen(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/**
 * custom_strncmp - compares two strings up to n bytes
 * @str1: first string to be compared
 * @str2: second string to be compared
 * @n: number of bytes
 *
 * Return: Returns the difference between str1 and str2
 */
int _strncmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}

/**
 * custom_strdup - duplicates a string
 * @str: string to be duplicated
 *
 * Return: Returns a pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
		return (NULL);

	len = custom_strlen(str);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *str != '\0'; str++, i++)
		ptr[i] = str[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
 * custom_strchr - locates a character in a string
 * @str: string to be checked
 * @ch: character to be located
 *
 * Return: Returns a pointer to the first occurrence of character
 * or NULL if character is not found
 */
char *_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (!ch)
		return (str);
	return (NULL);
}
