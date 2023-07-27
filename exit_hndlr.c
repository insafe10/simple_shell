#include "shell.h"

/**
 * exit_handler - handles the exit cmd & free allocated memory
 * @cmd: command
 * @input_line: input read from stdin
 * Return: None
 */

void exit_handler(char **cmd, char *input_line)
{
	free(input_line);
	free_buffers(cmd);
	exit(0);
}
