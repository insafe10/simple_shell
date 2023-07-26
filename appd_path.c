#include "shell.h"

/**
 * create_path - concatenates path to cmmd
 * @path: path of the cmd
 * @cmd: command
 * Return: Comcatenated string in Success, NULL on failure
 */

char *create_path(char *path, char *cmd)
{
	char *buffer;
	size_t i =0;
	size_t j = 0;

	if (!cmd)
		cmd = "";

	if (!path)
		path = "";

	size_t cmd_len = _strlen(cmd);
	size_t path_len = _strlen(path);

	buffer = malloc(sizeof(char) * (path_len + cmd_len + 2));
	if (!buffer)
		return(NULL);

	while (path[i])
	{
		buffer[i] = path[i];
		i++;
	}

	if (path_len > 0 && path[path_len - 1] != '/')
	{
		buffer[i] = '/';
		i++;
	}

	while (cmd[j])
	{
		buffer[i + j] = cmd[j];
		j++;
	}

	buffer[i + j] = '\0';
	return (buffer);
}
