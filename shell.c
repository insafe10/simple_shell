#include "shell.h"
/**
 * main - main entry point for the shell program
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment vector
 *
 * Return: 0 on successful completion
 */
int main(int argc, char **argv, char *envp[])
{
	char *input_line = NULL, *path_command = NULL, *executable_path = NULL;
	size_t buffer_size = 0;
	ssize_t line_size = 0;
	char **user_command = NULL, **path_directories = NULL;
	(void)envp, (void)argv;

	if (argc < 1)
		return (-1);
	signal(SIGINT, Handle_signl);
	while (1)
	{
		free_buffers(user_command);
		free_buffers(path_directories);
		free(path_command);
		Disp_prompt();
		line_size = getline(&input_line, &buffer_size, stdin);
		if (line_size < 0)
			break;

		info.ln_count++;

		if (input_line[line_size - 1] == '\n')
			input_line[line_size - 1] = '\0';
		user_command = split_string(input_line);
		if (user_command == NULL || *user_command == NULL || **user_command == '\0')
			continue;
		if (check_exect(user_command, input_line))
			continue;
		executable_path = get_path_env();
		path_directories = split_string(executable_path);
		path_command = search_executable(path_directories, user_command[0]);
		if (!path_command)
			perror(argv[0]);
		else
			execute(path_command, user_command);
	}

	if (line_size < 0 && flags.interactive)
	if (line_size < 0 && is_interactive())
		write(STDERR_FILENO, "\n", 1);
	free(input_line);
	return (0);
}
