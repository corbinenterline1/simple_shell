#include "holberton.h"

/**
 *
 *
 */
int main(void)
{
	char *line = NULL;
	char **cmds = NULL;
	size_t len = 0;
	ssize_t wr, read;
	char *start = "$ ";
	pid_t child;
	int status;

	while(STDOUT_FILENO)
	{
		wr = write(STDOUT_FILENO, start, 2);
		if (wr == -1)
			exit(EXIT_FAILURE);
		read = getline(&line, &len, stdin);
		if (read == EOF)
		{
			putchar(10);
			free(line);
			exit(EXIT_SUCCESS);
		}
		cmds = strtokarray(line);
		child = fork();
		if (child == -1)
		{
			freeptrarray(cmds);
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (child > 0)
			waitpid(child, &status, 0);/* or just wait()? */
		else
		{
			printf("I am the child!\n");
			execve(cmds[0], cmds, NULL);
			printf("Error: execve failed\n");
		}
	}
	exit(EXIT_SUCCESS);
}
