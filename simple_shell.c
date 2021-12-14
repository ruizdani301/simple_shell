#include "main.h"


/**
 * main - simple shell, command interpreter, loops to
 * display prompt, parse and execute simple commands
 * with arguments on interactive a non interactive mode.
 * @argc: variable
 * @argv: pointer
 * Return: if successful 0
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **args = NULL;

	(void)argc;
	shell_name = argv[0];

	signal(SIGINT, sigint_handler);

	do {
		line = read_line();

		if (check_for_builtins(&line))
		{
			free(line);
			continue;
		}

		args = tokenize_line(line);

		if (*args == NULL)
		{
			_free_pointers(line, args);
			continue;
		}
		exec_line(args);
		_free_pointers(line,args);
	} while (1);

	return (0);
}


/**
 * read_line - simple prompt "$" and read line from STDIN
 * sets terminal on interactive and non intereactive mode
 *
 * Return: buffer with the commands get from STDIN
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;

	line_counter++;

	fflush(stdin);

	if (isatty(STDIN_FILENO))
		_puts("\033[0;34m$ \033[0;35m");

	if (getline(&buffer, &buffer_size, stdin) == EOF)
	{
		if (isatty(STDOUT_FILENO))
			_puts("\n");
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}


/**
 * tokenize_line - function to split line arguments gets from STDIN
 *
 * @line: contains the imput get from STDIN
 *
 * Return: The tokenize string
 */
char **tokenize_line(char *line)
{
	int bufsize = BUFSIZE, i = 0;
	char **tokens;
	char *token = NULL;

	tokens = malloc(bufsize * sizeof(char *));

	if (tokens == NULL)
		exit(EXIT_FAILURE);

	token = strtok(line, " \t\n\r");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\n\r");
	}

	tokens[i] = NULL;
	return (tokens);
}

/**
 * exec_line - function to execute the commands parser
 *
 * @args: double pointer that contains the parser commands
 *
 * Return:  0 success
 */
int exec_line(char **args)
{
	pid_t pid;
	int status = 0;


	if (args[0] != NULL || args != NULL)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			if (execve(get_path(*args), args, environ) == -1)
			{
				_free(args);
				if (errno == ENOENT)
					exit(127);
				if (errno == EACCES)
					exit(126);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (status);
}
