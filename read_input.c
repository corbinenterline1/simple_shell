#include "holberton.h"
/**
* read_input - function
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
	if (read == 1)
	{
		free(line);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		return (NULL);
	}
	return (line);
}

/**
 * env_print - prints environment
 * @env: environment list
 */
void env_print(char **env)
{
	int a = 0, l = 0;
	char *str = NULL;

	while (env[a] != NULL)
	{
		str = env[a];
		l = _strlen(str);
		write(STDIN_FILENO, str, l);
		write(STDIN_FILENO, "\n", 1);
		a++;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * pathandfree - driver function for path creation and checking
 * @arg: argument to test
 * Return: new string if successful, NULL otherwise
 */
char *pathandfree(char *arg)
{
	list_p *path;
	char *ptr = NULL, *carg = NULL;

	path = pathlist();
	carg = arg;
	ptr = pathchecker(&path, carg);
	printf("ptr: %s\n", ptr);
	free_list(path);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
		return (ptr);
}
