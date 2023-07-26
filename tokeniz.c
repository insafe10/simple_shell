#include "shell.h"

/**
 * split_string - splits the input line into tokens
 * @input_line: the line to be tokenized
 *
 * Return: an array of strings (tokens)
 */
char **split_string(char *input_line)
{
    char *temp_line = NULL, *token = NULL, *delimiters = " \t\r\n";
    char **tokens = NULL;
    int token_size = 1;
    size_t index = 0, delimiter_flag = 0;

    temp_line = _strdup(input_line);
    if (!temp_line)
        return (NULL);

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

    tokens = malloc(sizeof(char *) * (token_size + 1));
    token = _strtok(input_line, delimiters);
    while (token)
    {
        tokens[index] = _strdup(token);
        if (tokens[index] == NULL)
        {
            free(tokens);
            free(temp_line);
            return (NULL);
        }
        token = _strtok(NULL, delimiters);
        index++;
    }

    tokens[index] = NULL;
    free(temp_line);
    return (tokens);
}
