#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/types.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_hist"
#define HIST_MAX	1024

extern char **environ;

#define MAX_INPUT_SIZE 1024

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Structure to hold information for function parameters
 * @arg: Command argument
 * @strarr: Array of strings generated from arg
 * @strpa: String path for the command
 * @argcount: Argument count
 * @line_count: Line count
 * @err_num: Error code for exit()
 * @linecount_flag: If set, count this line of input
 * @fname: Program filename
 * @env: Linked list local copy of environ
 * @hist: History node
 * @alias: Alias node
 * @environ: Custom modified copy of environ from linked list env
 * @env_changed: Set if environ was changed
 * @status: Process status
 * @readfd: Readfd value
 * @argv: arguments vector
 */

typedef struct passinfo
{
	char *arg;
	char **strarr;
	char *strpa;
	int argcount;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *hist;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	int readfd;
	char *argv;

} inf_t;

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */

typedef struct builtin
{
	char *type;
	int (*func)(inf_t *);
} builtin_table;

void display_prompt(void);
void execute_command(const char *command);
int interactive(inf_t *inf);
void li_print(const char *hali_shell);
int _isalpha(int c);
int _atoi(char *s);
int is_delim(char c, char *delim);

int _mycd(inf_t *inf);
int _myexit(inf_t *inf);
int _myhelp(inf_t *inf);

int hsh(inf_t *inf, char **args);
int find_builtin(inf_t *inf);
void find_cmd(inf_t *inf);
void fork_cmd(inf_t *inf);

int _myhist(inf_t *inf);
int _myalias(inf_t *inf);

void print_error(inf_t *inf, const char *message);
int is_cmd(inf_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(inf_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putla(char c, int la);
int _putsla(char *str, int la);

char *convert_num(long int, int, int);

int _strlen(char *str);
int _strcmp(const char *str1, const char *str2);
char *starts_with(const char *haystack, const char *needle);
char *hali_strcat(char *dest, char *src);
char *hali_strcpy(char *dest, char *src);
char *hali_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strnizer(char *str, const char *delimiter);
char **strtwo(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
char *get_env(inf_t *inf, const char *n);
int my_env(inf_t *inf);
int my_setenv(inf_t *inf);
int my_unsetenv(inf_t *inf);
int add_environ_list(inf_t *inf);

char **get_environ(inf_t *inf);
int _setenv(inf_t *inf, char *v, char *value);
int _unsetenv(inf_t *inf, char *v);

char *get_hist_file(inf_t *inf);
int write_hist(inf_t *inf);
int read_hist(inf_t *inf);
int build_hist_list(inf_t *inf, char *buf, int linecount);
int number_hist(inf_t *inf);

ssize_t get_input(inf_t *);

void clear_inf(inf_t *);
void set_inf(inf_t *, char *args[]);
void free_inf(inf_t *, int);

size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);
size_t print_list_str(const list_t *);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
#endif
