#include "holberton.h"
/**
* read_input - function
* @s: string to read
*
* Description: reads input from stdin
* Return: 0 (Exit Success)
*/
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "\n", 1);
		free(line);
		exit(EXIT_SUCCESS);
	}
	if (read == 0)/* do we need this??*/
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDIN_FILENO, "\n", 1);
			write(STDIN_FILENO, "$ ", 2);
			free(line);
			return (NULL);
/*continue;*/
		}
	}
	if (read == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			free(line);
			write(STDOUT_FILENO, "$ ", 2);
			printf("read is %zd\n", read);
			return(NULL);
		}
	/*	continue;*/
	}
	return (line);
}
