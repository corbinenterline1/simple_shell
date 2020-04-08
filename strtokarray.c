#include "holberton.h"

/**
 * strtokarray - creates an array of pointers to tokens from input string
 * @str: input string
 * Return: the double pointer, or NULL
 */
char **strtokarray(char *str)
{
	char **tokarray;
	char *tok;
	int c, c2, len, t;

	c = c2 = len = t = 0;
	len = strlen(str);
	str[len] = '\0';
	while (str[c] != '\0')
	{
		if (str[c + 1] == ' ' || str[c + 1] == '\0')
			t++;
		c++;
	}
	if (c == 0)
		return (NULL);
	tokarray = malloc(sizeof(char) * (t + 1));
	if (tokarray == NULL)
	{
		free(tokarray);
		return (NULL);
	}
	tok = strtok(str, " ");
	c = 0;
	while (tok != NULL)
	{
		len = strlen(tok);
		tokarray[c] = malloc(len + 1);
		if (tokarray[c] == NULL)
		{
			freearray(tokarray);
			return (NULL);
		}
		strncpy(tokarray[c], tok, len + 1);
		tok = strtok(NULL, " ");
		c++;
	}
	tokarray[c] = NULL;
	return (tokarray);
}