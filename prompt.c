#include "holberton.h"

/**
 *
 *
 */
int main(void)
{
	char *line = NULL;
	char **cmds;
	size_t len = 0;
	ssize_t wr, read;
	char *start = "$ ";
	pid_t child;
	int a = 0, status, pidstatus;

	if (isatty(STDIN_FILENO))
		wr = write(STDOUT_FILENO, start, 2);
	if (wr == -1)
		exit (EXIT_FAILURE);
	while ((read = getline(&line, &len, stdin)))
	{
		if (read == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDIN_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}
		line[read - 1] = '\0';
		cmds = strtokarray(line);
		while (cmds[a])
		{
			printf("argument %d: %s\n", a, cmds[a]);
			a++;
		}
		child = fork();
		if (child == -1)/* Fork failed */
		{
			freeptrarray(cmds);
			free(line);
			dprintf(STDERR_FILENO, "fork failed\n");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)/* I am the child! */
		{
			status = execve(cmds[0], cmds, NULL);
		}
		else/* pid above 0, so thats ppid. wait until child ends */
		{
			waitpid(child, &pidstatus, WUNTRACED);	
		}
		if (status < 0)
		{
			dprintf(STDERR_FILENO, "%s: Command not found\n", cmds[0]);
			status = 0;
		}
		if (isatty(STDIN_FILENO))
			wr = write(STDOUT_FILENO, start, 2);
		a = len = 0;
		line = NULL;
	}
	exit(EXIT_SUCCESS);
}
