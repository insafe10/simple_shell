#include "shell.h"

/**
 * count_tokens - Count the numbers of tokens
 * @input_line: input line
 * Return: number of tokens
 */

int count_tokens(char *input_line)
{
	char *temp_line = _strdup(input_line);
	char *delimiters;
	int token_size, delimiter_flag;

	if (!temp_line)
		return (-1);

	delimiters = " \t\r\n";
	token_size = 1;
	delimiter_flag = 0;

	while (*temp_line)
	{
		if (_strchr(delimiters, *temp_line) != NULL && delimiter_flag == 0)
		{
			token_size++;
			delimiter_flag = 1;
		}
		else if (_strchr(delimiters, *temp_line) == NULL && delimiter_flag == 1)
			delimiter_flag = 0;

		temp_line++;
	}

	free(temp_line);
	return (token_size);
}

/**
 * create_tokens - Create an array of tokens from the input line.
 * @input_line: The input line to be tokenized.
 * Return: The array of tokens.
 */

char **create_tokens(char *input_line)
{
	char **tokens = NULL;
	int token_size = count_tokens(input_line);
	char delimiters[] = " \t\r\n";
	char *token = strtok(input_line, delimiters);
	int index = 0;

	if (token_size <= 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (token_size + 1));
	if (!tokens)
		return (NULL);

	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delimiters);
		index++;
	}

	tokens[index] = NULL;
	return (tokens);
}

/**
 * split_string - splits the input line into token
 * @input_line: the line to be tokenized
 * Return: tokens
 */

char **split_string(char *input_line)
{
	return (create_tokens(input_line));
}
