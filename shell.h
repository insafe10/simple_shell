#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

extern char **environ;

void Disp_prompt(void);
void execute(char *cmd_path, char **args);

char *create_path(char *path, char *cmd);
int check_exect(char **args, char *buffer);
int execute_builtin(char **cmds, char *input_line);
void Handle_signl(int signal_num);
char *get_path_env(void);
void print_environment(void);
char *search_executable(char **search_paths, char *cmd);
int _putchar(char c);
int print_string(char *s);
char **split_string(char *input_line);
void exit_handler(char **cmd, char *input_line);

int _strcmp(char *str1, char *str2);
int _strlen(char *str);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *str);
char *_strchr(char *str, char ch);


void free_buffers(char **buf);


struct flags
{
	bool interactive;
} flags;

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;
#endif 
