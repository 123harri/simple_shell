#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	char input[1024];
	size_t input_len;

	inf_t my_inf;

	while (interactive(&my_inf))
	{
		display_prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input_len = strlen(input);
		if (input_len > 0 && input[input_len - 1] == '\n')
		{
			input[input_len - 1] = '\0';
		}
			execute_command(input);
	}

		return (0);
}
