#include "shell.h"

/**
 * execute_command - executes command
 * @child_pid: the child processor
 * @perror: prints error
 *
 * Wait: returns NULL on success
 *
 */

void execute_command(const char *command)
 {
    pid_t child_pid = fork();

    if (child_pid == -1)
 {
        li_print("Error forking process.\n");
        exit(EXIT_FAILURE);
    }
 else if (child_pid == 0)
 {
        char *args[1024];
        int arg_count = 0;

        char *token = strnizer((char *)command, " ");
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        execvp(args[0], args);

        li_print("Error executing command.\n");
        exit(EXIT_FAILURE);
    }
 else
 {
        wait(NULL);
    }
}
