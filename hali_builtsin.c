#include "shell.h"
/**
 * _myexit - Exits the shell.
 * @args: Array of arguments.
 *
 * Return: The exit code.
 */
int _myexit(char *args[])
{
	int exit_code = 0;

	if (args[1])
	{
		int exit_check = _atoi(args[1]);

		if (exit_check == -1)
		{
			li_print("Illegal number: ");
			li_print(args[1]);
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

#include "shell.h"

/**
 * _myhelp - Displays help information.
 * @args: Array of arguments.
 *
 * Return: 0 on success, or an appropriate error code.
 */
int _myhelp(char *args[])
{
	(void)args;

	li_print("Help function is not yet implemented.\n");

	return (0);
}

#include "shell.h"

/**
 * _mycd - Changes the current directory of the process.
 * @args: Array of arguments.
 *
 * Return: 0 on success, or an appropriate error code.
 */
int _mycd(char *args[])
{
	char *dir;

	if (!args[1])
	{
		dir = getenv("HOME");
		if (!dir)
			dir = "/";
	}
	else if (_strcmp(args[1], "-") == 0)
	{

		dir = getenv("OLDPWD");
		if (!dir)
			dir = "/";
	}
	else
	{
		dir = args[1];
	}

	if (chdir(dir) == -1)
	{
		li_print("can't cd to ");
		li_print(args[1]);
		li_print("\n");
		return (1);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", getcwd(NULL, 0), 1);

	return (0);
}
