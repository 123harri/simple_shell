#include "shell.h"
/**
 * execute_command - it executes commands in a child process
 * and waits for it to complete
 * @command: The command to be executed
 * This function creates a child process using fork(), and the child process
 * executes the specified command using execlp(). The parent process waits
 * for the child to complete
 */

void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execlp(command, command, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
