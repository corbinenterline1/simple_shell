#include "holberton.h"


/**
 * freeptrarray - frees all pointers from the array
 * @ptr: pointer to pointer array
 */
void freeptrarray(char **ptr)
{
	int c = 0;

	while (ptr[c] != NULL)
		c++;

	while (c >= 0)
	{
		free(ptr[c]);
		c--;
	}
	free(ptr);
}
