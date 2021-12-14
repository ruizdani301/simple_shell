#include "main.h"

/**
 * __error - show the specific error
 * @arg: pointer
 * @size: counter
 * @command: pointer
 */

void __error(char *arg, int size, char *command)
{
	_puts(arg);
	_puts(": ");
	_puts_number(size);
	_puts(": ");
	_puts(command);
	_puts(": not found");
	_puts("\n");
}

/**
 * _puts_number - prints char to int
 * @size: integer
 */

void _puts_number(int size)
{
	int div, len;
	unsigned int n1;

	div = 1;
	len = 0;

	n1 = size;

	for (; n1 / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + n1 / div);
		n1 %= div;
		div /= 10;
	}
}


/**
 * sigint_handler - catches SIGINT signal and reset signal
 * @sigint: signal from stdint
 */
void sigint_handler(int sigint)
{
	(void)sigint;
	signal(SIGINT, sigint_handler);
	_puts("\n");
	_puts("\033[0;34m$ \033[0;35m");
	fflush(stdout);
}
