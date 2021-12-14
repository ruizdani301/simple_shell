#include "main.h"


/**
 * _strcmp - compares two strings
 * @s1: first string as parameter
 * @s2: second string as parameter
 * Return: 0 if  s1 = '\n' or any other value  if
 *  s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}


/**
 * _strlen - get the len of a string
 * @s: string
 * Return: a integer for count chars
 */
int _strlen(const char *s)
{
	const char *end = s;

	while (*end++)
	{};
	return (end - s - 1);
}


/**
 * *_strcat - concatenates two strings
 * @s1: string to concatenate
 * @s2: other string to concatenate
 *
 * Return: pointer to the new string created (Success), or NULL (Error)
 */
char *_strcat(char *s1, char *s2)
{
	char *s3;
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (s3 == NULL)
	{
		free(s3);
		return (NULL);
	}

	i = 0;
	j = 0;

	if (s1)
	{
		while (i < len1)
		{
			s3[i] = s1[i];
			i++;
		}
	}

	if (s2)
	{
		while (i < (len1 + len2))
		{
			s3[i] = s2[j];
			i++;
			j++;
		}
	}
	s3[i] = '\0';

	return (s3);
}


/**
 * _puts - prints a string in STDOUT
 *
 * @str: string to printed
 *
 * Return: integer
 */
int _puts(char *str)
{
	int i;
	char *s = str;

	if (s == NULL)
		s = "(null)";
	i = _strlen(s);

	write(STDOUT_FILENO, s, i);
	return (i);
}
/**
 * _putchar - prints a character
 *
 * @c: character to printed
 *
 * Return: integer
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
