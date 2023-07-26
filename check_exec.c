#include "shell.h"

/**
 * check_exect - Checks if the cmd is a built in func or externl cmd
 * @args: tpkenized input
 * @buffer: line derived from the getlinefnc
 *
 * Return: 1 if the cmd is executed, 0 otherwise
 */

int check_exect(char **args, char *buffer)
{
	if (execute_builtin(args, buffer))
		return (1);
	else if (*args[0] == '/')
	{
		execute(args[0], args);
		return (1);
	}
	return (0);
}
