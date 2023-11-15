#include "shell.h"
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
		_puts("hali_shell exits \n");
	if (!inf->argv[1])
	{
		dir = _getenv(inf, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(inf, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
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
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(inf_t *inf)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("hoping my hali_shell to run \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
