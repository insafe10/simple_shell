#include "shell.h"

/**
 * search_executable - check if the cmd is available in the pth
 * @search_paths: tokenized paths form Path environt
 * @cmd: command
 *
 * Return: return path of the exutable, NULL otherwise
 */

char *search_executable(char **search_paths, char *cmd);
{
	char *result;
	int i = 0;

	while (search_paths[i])
	{
		result = create_path(search_paths[i], cmd);
		if (access(result, F_OK | X_OK) == 0)
			return (result);
		free(result);
		i++;
	}
	return (NULL);
}
