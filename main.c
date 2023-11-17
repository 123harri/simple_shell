#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	size_t input_len;
	char input[1024];
	inf_t inf = {0};

	while (interactive(&inf))
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
