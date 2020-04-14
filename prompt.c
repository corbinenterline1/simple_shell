#include "holberton.h"
/**
* main - Entry point for program hsh
*
* Description: program for shell implementation
* Return: 0 Always Successful
*/
int main(void)
{
	char *line = NULL;
	char **cmds;
	size_t len = 0;
	ssize_t wr, read;
	char *start = "$ ";
	int a = 0;

	if (isatty(STDIN_FILENO))
		wr = write(STDOUT_FILENO, start, 2);
	if (wr == -1)
		exit(EXIT_FAILURE);
	while (STDOUT_FILENO) /*(read_input(line))*/ /*((read = getline(&line, &len, stdin)))
	{
		if (read == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDIN_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (read == 0)
		{
			if (isatty(STDIN_FILENO))
				write(STDIN_FILENO, "\n", 1);
			continue;
		}
		if (read == 1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, start, 2);
			continue;
		}*/
	{
		line = read_input();
		cmds = strtokarray(line);
		while (cmds[a])
		{
			printf("argument %d: %s\n", a, cmds[a]);
			a++;
		}
		if (cmds == NULL)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, start, 2);
			a = len = 0;
			continue;
		}
		if (strcmp("exit", cmds[0]) == 0)
		{
			free(line);
			freeptrarray(cmds);
			exit(0);
		}
		execute_input(cmds);
		if (isatty(STDIN_FILENO))
			wr = write(STDOUT_FILENO, start, 2);
		free(line);
		a = len = 0;
		line = NULL;
	}
	exit(EXIT_SUCCESS);
}
