#include "shell.h"

/**
 * get_path_env - finds the path
 *
 * Return: pointer to the path value, NULL if not found
 */

char *get_path_env(void)
{
	char **env_ptr = environ;
	int i;
	char *path_value = NULL;

	while (*env_ptr)
	{
		if (_strncmp(*env_ptr, "PATH=", 5) == 0)
		{
			path_value = *env_ptr;
			for (i = 0; *path_value && i < 5; i++)
			{
				path_value++;
			}
			return (path_value);
		}
		env_ptr++;
	}
	return (NULL);
}
