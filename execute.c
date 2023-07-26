#include "shell.h"

/**
 * execute - Executes commands
 * @cmd_path: The command path
 * @args: cmd arguments
 * Return: None
 */

void execute(char *cmd_path, char **args)
{
	pid_t child_pid;
	char **env = environ;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork error");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(cmd_path, args, env) == -1)
		{
			perror("execve error");
			free(cmd_path);
			free_buffers(args);
			exit(98);
		}
	}
	else
	{
		wait(&status);
	}
}
