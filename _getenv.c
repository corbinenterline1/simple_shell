#include "holberton.h"

/*int main (void)
{

	printf("PATH: %s\n", _getenv("PATH"));
	printf("LOGNAME: %s\n", _getenv("LOGNAME"));
	printf("ROOT: %s\n", _getenv("ROOT"));
	return (0);
}
*/
/**
 *
 *
 */
char *_getenv(const char :*name)
{
	char **ep = environ;
	char *np;
	int a, b;

	a = b = 0;
	while (ep[a] != NULL)
	{
		b = 0;
		np = ep[a];
		while (np[b] != '=')
			b++;
		if (strncmp(np, name, b) == 0)
		{
			while (b > 0)
			{
				np++;
				b--;
			}
			return (++np);

		}
		a++;
	}
	return (NULL);
}
