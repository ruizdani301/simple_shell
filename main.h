#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define BUFSIZE 64

#define NONE "\033[m"
#define RED "\033[1;37;41m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32;32m"
#define GRAY "\033[1;30m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"

/**
 * struct built_ins - Associate a command with its funtion
 *
 * @name: corresponding to command name
 * @f: function pointer to corresponfind function
 * Description: the mainly purpouse is matching a command with its
 * correspondig function which is a function pointer.
 */
typedef struct built_ins
{
	char *name;
	void (*f)();
} builtins_t;

extern char **environ;
char *shell_name;

unsigned int line_counter;
/* strings */
int _strlen(const char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
int _puts(char *str);
int _putchar(char c);
void _puts_number(int size);

char *_getenv(char *input);
char *get_path(char *command);
char **tokenize_line(char *line);
char *read_line(void);
int exec_line(char **args);

/* built-ins */
void (*check_for_builtins(char **args))(char **args);
void __exit(char **ptr);
void __env(void);
void _free(char **d_pointer);
void _free_pointers(char *line, char **args);
void __error(char *arg, int size, char *command);

void sigint_handler(int sigint);

#endif
