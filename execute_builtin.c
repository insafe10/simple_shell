#include "shell.h"

/**
 * execute_builtin - builtin the execution
 * @cmds: cmmnds
 * @input_line: input read from stdin
 *
 * Return: 1 if executed, 0 otherwise
 */

int execute_builtin(char **cmds, char *input_line)
{
	struct  builtin builtin = {"env", "exit"};

	if (_strcmp(*cmds, builtin.env) == 0)
	{
		print_environment();
		return (1);
	}
	else if (_strcmp(*cmds, builtin.exit) == 0)
	{
		exit_handler(cmds, input_line);
		return (1);
	}
	return (0);
}
