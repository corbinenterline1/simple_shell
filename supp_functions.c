#include "holberton.h"
/**
* _strncpy - function
* @dest: copy to string
* @src: copy from string
* @n: at parameter
*
* Description: copies a string to the nth value.
* Return: dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int len;

	for (len = 0; src[len]; len++)
	{
		if (n > len)
		dest[len] = src[len];
	}
	for ( ; n > len; len++)
	{
		dest[len] = '\0';
	}
	return (dest);
}
/**
* _strlen - function
* @s: first operand & pointer
*
* Description: function that returns the length of a string
* Return: Always 0
*/
int _strlen(char *s)
{
	int index = 0;

	while (*s != '\0')
	{
		index++;
		s++;
	}
	return (index);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
