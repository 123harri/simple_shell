#include "shell.h"

/**
 * main - entry point
 * @argcount: argument count
 * @argvect: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argcount, char **argvect)
{
	inf_t inf[] = { INF_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (argcount == 2)
	{
		fd = open(argvect[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argvect[0]);
				_eputs(": 0: exit ");
				_eputs(argvect[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inf->readfd = fd;
	}
	populate_env_list(inf);
	read_hist(inf);
	hsh(inf, argvect);
	return (EXIT_SUCCESS);
}
