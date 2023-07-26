#include "shell.h"

/**
 * print_environment - prints the environmt strings to stdout
 *
 * Return: void
 */

void print_environment(void)
{
	int idx = 0;
	char **env_vars = environ;

	while (env_vars[idx])
	{
		write(STDOUT_FILENO, env_vars[idx], _strlen(env_vars[idx]));
		write(STDOUT_FILENO, "\n", 1);
		idx++;
	}
}
