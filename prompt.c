#include "holberton.h"

/**
* main - Entry point to shell program
*
* Description: Simple shell program
* Return: 0 Successful
*/
int main(void)
{
	char *line = NULL;
	char **cmds;
	size_t len = 0;
	ssize_t wr, read;
	char *start = "$ ";
	pid_t child;
	int a = 0, pidstatus;
	struct stat sstat;

	if (isatty(STDIN_FILENO))
		wr = write(STDOUT_FILENO, start, 2);
	if (wr == -1)
		exit(EXIT_FAILURE);
	while ((read = getline(&line, &len, stdin)))
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
				wr = write(STDOUT_FILENO, start, 2);
			a = len = 0;
			continue;
		}
		if (strcmp("exit", cmds[0]) == 0)
			exit(0);

		child = fork();
		if (child == -1)/* Fork failed */
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)/* I am the child! */
		{
			if (stat(cmds[0], &sstat) == 0)
				execve(cmds[0], cmds, NULL);
			else
			{
				perror("./hsh");
				free(line);
				freeptrarray(cmds);
				exit(EXIT_SUCCESS);
			}
		}
		else/* pid above 0, so thats ppid. wait until child ends */
		{
			waitpid(child, &pidstatus, WUNTRACED);
			free(line);
			freeptrarray(cmds);
		}
		if (isatty(STDIN_FILENO))
			wr = write(STDOUT_FILENO, start, 2);
		a = len = 0;
		line = NULL;
	}
	exit(EXIT_SUCCESS);
}
