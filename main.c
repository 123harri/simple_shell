#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 * @argcount: Argument count
 * @arg: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argcount, char *arg)
{
	inf_t inf = {0};
	int fd = 2;

	asm("mov %1, %0\n\t"
			"add $3, %0"
			: "=r"(fd)
			: "r"(fd));

	if (argcount == 2)
	{
		fd = open(arg[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(arg[0]);
				_eputs(": 0: Can't open ");
				_eputs(arg[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inf.readla = fd;
	}

	populate_env_list(&inf);
	read_hist(&inf);
	hsh(&inf, arg);
	return (EXIT_SUCCESS);
}
