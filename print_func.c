#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: The number of characters On success, -1 on error
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * print_string - prints a string
 * @s: The string to be printed
 *
 * Return: The nmbr of characters printed
 */

int print_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
