#include "main.h"

/**
 * _free - free memory allocation
 *@ptr: double pointer
 * Return: void
 */
void _free(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;

	while (ptr[i])
	{
		free(ptr[i]);
		++i;
	}

	if (ptr[i] == NULL)
		free(ptr[i]);

	free(ptr);
}
/**
 * _free_pointers - free memory from main pointers
 * @line: pointer to line
 * @args: pointer to args
 *
 */
void _free_pointers(char *line, char **args)
{
	free(args);
	free(line);

}