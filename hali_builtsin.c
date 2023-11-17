#include "shell.h"

/**
 * _myexit - Exits the shell.
 * @inf: Structure containing information about the shell
 *
 * Return: The exit code.
 */
int _myexit(inf_t *inf)
{
	int exit_code = 0;

	if (inf->strarr[1])
	{
		int exit_check = _atoi(inf->strarr[1]);

		if (exit_check == -1)
		{
			li_print("Illegal number: ");
			li_print(inf->strarr[1]);
			li_print("\n");
			exit_code = 2;
		}
		else
		{
			exit_code = exit_check;
		}
	}

	exit(exit_code);
}
/**
 * _myhelp - Displays help information.
 * @inf: Structure containing information about the shell
 *
 * Return: 0 on success, or an appropriate error code.
 */
int _myhelp(inf_t *inf)
{
	(void)inf;

	li_print("Help function is not yet implemented.\n");

	return (0);
}

/**
 * _mycd - Changes the current directory of the process.
 * @inf: Structure containing information about the shell
 *
 * Return: 0 on success, or an appropriate error code.
 */
int _mycd(inf_t *inf)
{
	char *dir;

	if (!inf->strarr[1])
	{
		dir = getenv("HOME");
		if (!dir)
			dir = "/";
	}
	else if (_strcmp(inf->strarr[1], "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (!dir)
			dir = "/";
	}
	else
	{
		dir = inf->strarr[1];
	}

	if (chdir(dir) == -1)
	{
		li_print("can't cd to ");
		li_print(inf->strarr[1]);
		li_print("\n");
		return (1);
	}

	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", getcwd(NULL, 0), 1);

	return (0);
}
