#include "main.h"


/**
 * check_for_builtins - get the function corresponding to built-in name
 *
 * @args: double pointer, store the command line buffer
 *
 * Return: return a function corresponding to especifier
 */
void (*check_for_builtins(char **args))(char **args)
{
	builtins_t builtins_list[] = {
		{"exit", __exit},
		{"env", __env},
		{NULL, NULL}};

	int i = 0;

	if (args[0] == NULL)
	{
		free(args);
		exit(127);
	}

	for (; builtins_list[i].name != NULL ; i++)
	{
		if (_strcmp(args[0], builtins_list[i].name) == 0)
			break;
	}

	if (builtins_list[i].f != NULL)
		builtins_list[i].f(*args);

	return (builtins_list[i].f);
}

/**
 * __exit - Built-in function to allow exit from terminal
 *
 * @ptr: doouble pointer to be free
 *
 */
void __exit(char **ptr)
{
	int _err = 0;

	if (line_counter > 1)
		_err = 2;
	free(ptr);
	exit(_err);
}


/**
 * __env - prints the environmente vars
 *
 * Return: void
 */
void __env(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i++]);
		_puts("\n");
	}
}
