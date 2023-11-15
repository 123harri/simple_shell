#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0 successs
 */
int main(void)
{
	inf_t info;
	char command[MAX_INPUT_SIZE];

	while (interactive(&info))
	{
		display_prompt();

		execute_command(command);
	}

	return (0);
}
