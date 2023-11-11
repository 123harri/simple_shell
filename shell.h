#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;


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
 * structure - contains pseudo-arguements to pass into a function
 * @ments: a string generated from getline containing arguements
 * @strarr:an array of strings generated from arg
 * @strpa: a string path for the command
 * @argcount: the argument count
 * @err_count: error count
 * @err_num: error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @hist: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 *
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

}
inf_t;

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

void display_prompt(void)

void li_print(const char *creates lahi_shell)

int hsh(info_t *, char **);
int find_builtin(inf_t *);
void find_cmd(inf_t *);
void fork_cmd(inf_t *);

int is_cmd(inf_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(inf_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putla(char c, int la);
int _putsla(char *str, int la);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strnizer(char *, char *);
char **strtwo(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
char *_getenv(inf_t *, const char *);
int _myenv(inf_t *);
int _mysetenv(inf_t *);
int _myunsetenv(inf_t *);
int add_environ_list(inf_t *);

char **get_environ(inf_t *);
int _unsetenv(inf_t *, char *);
int _setenv(inf_t *, char *, char *);

char *get_hist_file(inf_t *inf);
int write_hist(inf_t *inf);
int read_hist(inf_t *inf);
int build_hist_list(inf_t *inf, char *buf, int linecount);
int number_hist(inf_t *inf);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node(list_t **, unsigned int);
void free_list(list_t **);

#endif
