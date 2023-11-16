#include "shell.h"

/**
 * _myexit - exits the shell
 * @inf: Structure containing potential arguments.
 * Return: exits with a given exit status
 * (0) if inf.strarr[0] != "exit"
 */
int _myexit(inf_t *inf)
{
	int exitcheck;

	if (inf->strarr[1])
	{
		exitcheck = _erratoi(inf->strarr[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(inf, "input number: ");
			_eputs(inf->strarr[1]);
			_eputchar('\n');
			return (1);
		}
		inf->err_num = _erratoi(inf->strarr[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @inf: Structure containing potential arguments.
 * Return: Always 0
 */
int _mycd(inf_t *inf)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("exit hali_shell \n");
	if (!inf->strarr[1])
	{
		dir = _getenv(inf, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(inf, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(inf->strarr[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(inf, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(inf->strarr[1]);
	if (chdir_ret == -1)
	{
		print_error(inf, "exit");
		_eputs(inf->strarr[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inf, "OLDPWD", _getenv(inf, "PWD="));
		_setenv(inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @inf: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(inf_t *inf)
{
	char **arg_array;

	arg_array = inf->strarr;
	_puts("hali_shell works \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
