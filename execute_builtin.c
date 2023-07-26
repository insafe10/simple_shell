#include "shell.h"

/**
 * execute_handle - handles the execution
 * @cmds: cmmnds
 * @input_line: input read from stdin
 *
 * Return: 1 if executed, 0 otherwise
 */

int execute_builtin(char **cmds, char *input_line)
{
	struct builtin {
		char *env;
		char *exit;
	} builtin = {"env", "exit"};

	if (_strcmp(*cmds, builtin.exit) == 0)
	{
		print_environment();
		return (1);
	}
	else if (_strcmp(*cmds, builtin.exit) == 0)
	{
		exit(cmds, input_line);
		return (1);
	}
	return (0);
}
