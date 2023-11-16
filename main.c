#include "shell.h"
/**
 * main - entry point
 * Return: always 0 on success
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
