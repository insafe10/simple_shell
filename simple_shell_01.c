#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64


void parse_command(char *command, char *arguments[]) {
    char *token = strtok(command, " \t\n");
    int i = 0;
    while (token != NULL && i < MAX_ARGUMENTS - 1) {
        arguments[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    arguments[i] = NULL; 
}

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
    } else if (pid == 0) {
    
        char *arguments[MAX_ARGUMENTS];
        parse_command(command, arguments);

        if (execve(arguments[0], arguments, NULL) == -1) {
            perror("execve");
            _exit(EXIT_FAILURE);
        }
    } else {
        
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
    
        printf("simple_shell$ ");
        fflush(stdout);

      
        if (fgets(command, sizeof(command), stdin) == NULL) {
      
            printf("\n");
            break;
        }

        execute_command(command);
    }

    return 0;
}
