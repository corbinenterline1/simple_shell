#include "holberton.h"
/**
* main - Entry point for program hsh
*
* Description: program for shell implementation
* Return: 0 Always Successful
*/
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **cmds;
	size_t len = 0;
	ssize_t wr;
	char *start = "$ ";
	int a = 0;

	if (isatty(STDIN_FILENO))
		wr = write(STDOUT_FILENO, start, 2);
	if (wr == -1)
		exit(EXIT_FAILURE);
	while (STDOUT_FILENO)
	{
		line = read_input();
		if (line == 0)
			continue;
		cmds = strtokarray(line);
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
		if (strcmp("env", cmds[0]) == 0)
		{
			free(line);
			freeptrarray(cmds);
			env_print(env);
			a = len = 0;
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, start, 2);
			continue;

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
