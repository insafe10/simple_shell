#include "shell.h"

/**
 * Disp_prompt - Prints $ to mention that shell is ready
 * The functions checks if the shell is in interactive mode
 * and writes the prompt to STDERR if it is 
 */

void Disp_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;

	if (flags.interactive)
	{
		char prompt[] = "$ ";
		
		write(STDERR_FILENO, prompt, sizeof(prompt) - 1);
	}
}

int main(void)
{
	Disp_prompt();
}
