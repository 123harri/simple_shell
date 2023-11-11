#include "shell.h"


/**
 * li_print - Prints a string to the standard output.
 * @lahi_shell: The string to be printed
 * This function writes the specified string to the standard output.
 * It uses the write system call to achieve this
 */
void li_print(const char *lahi_shell)
{
	write(STDOUT_FILENO, lahi_shell, strlen(lahi_shell));
}
