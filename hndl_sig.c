#include "shell.h"

/**
 * Handle_signl - handles the signal when shell is in interc mode
 * @signal_num: The signal number
 *
 * Return: void
 */

void Handle_signl(int signal_num)
{
	if (signal_num == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		write(STDERR_FILENO, "$ ", 2);
	}
}
