#include "main.h"

/**
 * _getenv - retrieves env variable that matches input string
* @input: input string
* Return: string of env variable
 */
char *_getenv(char *input)
{
	char *tok, *path;

	while (*environ)
	{
		tok = strtok(*environ, "=");
		if (_strcmp(tok, input) == 0)
		{
			path = strtok(NULL, "=");
			return (path);
		}
		environ++;
	}
	return (NULL);
}

/**
 * get_path - function to get the path to executable
 *
 * @cmd: cmd to find path
 *
 * Return: char pointer with the path
 */
char *get_path(char *cmd)
{
	char *path = NULL, *token, *newpath, *str_cpy;
	struct stat stats;

	if (stat(cmd, &stats) == 0)
		return (cmd);

	path = _getenv("PATH");

	if (path == NULL)
		exit(127);

	str_cpy = cmd;
	cmd = _strcat("/", cmd);
	token = strtok(path, ":");

	while (token)
	{
		newpath = _strcat(token, cmd);

		if (stat(newpath, &stats) == 0)
		{
			free(cmd);
			return (newpath);
		}
		free(newpath);
		token = strtok(NULL, ":");
	}
	__error(shell_name, line_counter, str_cpy);
	free(cmd);

	return (str_cpy);
}
