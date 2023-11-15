#include "shell.h"

/**
 * _myexit - exits the shell
 * @inf: Structure containing potential arguments.
 * Return: exits with a given exit status
 * (0) if inf.argv[0] != "exit"
 */
int _myexit(inf_t *inf)
{
	int exitcheck;

	if (inf->arg[1])
	{
		exitcheck = atoi(&(inf->arg[1]));
		if (exitcheck == -1)
		{
			inf->status = 2;
			print_error(inf, "Illegal number: ");
			_eputs(&(inf->arg[1]));
			_eputchar('\n');
			return (1);
		}
		inf->err_num = atoi(&(inf->arg[1]));
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}
