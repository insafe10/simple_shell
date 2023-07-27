#include "shell.h"

/**
 * handle_input - read input from  user
 *
 * Return: the users cmd
 */

char **handle_input(void)
{
	char *input_line = NULL;
	size_t buffer_size = 0;
	size_t line_size = 0;
	char **user_command = NULL;

	Disp_prompt();
	line_size = getline(&input_line, &buffer_size, stdin);
	if (line_size <= 0)
	{
		free(input_line);
		return (NULL);
	}

	info.ln_count++;

	if (input_line[line_size - 1] == '\n')
		input_line[line_size - 1] = '\0';
	user_command = split_string(input_line);
	free(input_line);

	return (user_command);
}

/**
 * execute_command - execute command
 * @user_command: the cmd to be executed
 * @argv: argumet vector
 */
void execute_command(char **user_command, char **argv)
{
	char *input_line = NULL;
	char *executable_path = NULL;
	char **path_directories = NULL;
	char *path_command = NULL;

	if (user_command == NULL || *user_command == NULL || **user_command == '\0')
		return;
	if (check_exect(user_command, input_line))
		return;
	executable_path = get_path_env();
	path_directories = split_string(executable_path);
	path_command = search_executable(path_directories, user_command[0]);

	if (!path_command)
		perror(argv[0]);
	else
		execute(path_command, user_command);

	free_buffers(path_directories);
	free(path_command);
}

/**
 * main - main entry point
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment vector
 * Return: 0 on success
 */

int main(int argc, char **argv, char *envp[])
{
	char **user_command = NULL;
	(void)envp, (void)argv;

	if (argc < 1)
		return (-1);

	signal(SIGINT, Handle_signl);

	while (1)
	{
		user_command = handle_input();
		if (user_command == NULL)
			break;

		execute_command(user_command, argv);
		free_buffers(user_command);
	}

	if (flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	return (0);
}
