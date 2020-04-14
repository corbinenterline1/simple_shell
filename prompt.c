#include "holberton.h"
/**
* main - Entry point for program hsh
* @ac: input argument count
* @av: input argument vector
* @env: environment list
* Return: 0 Always Successful
*/
int spacecheck(char *line);
int main(__attribute__((unused))int ac, __attribute((unused))char **av, char **env)
{
	char *line = NULL;
	char **cmds;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	while (STDOUT_FILENO)
	{
		line = read_input();
		if (line == NULL)
		{
			free(line);
			continue;
		}
		if (spacecheck(line) == 1)
			continue;
		cmds = strtokarray(line);
		free(line);
		if (cmds == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
			continue;
		}
		if (_strcmp("exit", cmds[0]) == 0)
		{
			freeptrarray(cmds);
			exit(0);
		}
		if (_strcmp("env", cmds[0]) == 0)
		{
			env_print(env);
			freeptrarray(cmds);
			continue;
		}
		execute_input(cmds);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	exit(EXIT_SUCCESS);
}

/**
 * spacecheck - checks if line is all whitespace
 * @line: input line to check
 * Return: 1 if all whitespaces, 0 otherwise
 */
int spacecheck(char *line)
{
	int a = 0;

	while (line[a] == ' ' || line[a] == '\n' || line[a] == '\t' ||
		line[a] == '\v' || line[a] == '\f' || line[a] == '\r' ||
		line[a] == '\0')
	{
		if (line[a] == '\0')
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
			return (1);
		}
		else
			a++;
	}
	return (0);
}
