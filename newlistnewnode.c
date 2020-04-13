#include "holberton.h"
char *str_concat(char *s1, char *s2)
{
	char *cpy = NULL;
	int t, a, b;

	t = a = b = 0;
	if (s1 == NULL)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(1);
		*s2 = '\0';
	}
	t = _strlen(s1);
	t += _strlen(s2);
	t += 1;
	cpy = malloc(sizeof(char) * t);
	if (cpy == NULL)
		return (NULL);
	for (a = 0; s1[a] != '\0'; a++)
		cpy[a] = s1[a];
	for (b = 0; a != t && s2[b] != '\0'; b++, a++)
	{
		cpy[a] = s2[b];
	}
	cpy[a] = '\0';
	return (cpy);
}

char *pathchecker(char *arg)
{
	list_p *pather;
	struct stat statty;
	char *append = "/";
	char *str, *str2;/*str2 was pathcpy*/
	
	str = NULL;
	str2 = NULL;
	pather = pathlist();/* free pather at end */

	while (pather != NULL)
	{
		str2 = pather->str;
		str = str_concat(str2, append);/* need to free str2 */
		str2 = str_concat(str, arg);
		free(str);
		if (stat(str2, &statty) == 0)
		{
			free_list(pather);
			return (str2);
		}
		else
		{
		free(str2);
		/*str = NULL;
		str2 = NULL;*/
		pather = pather->next;
		}
	}
	free(pather);
	free(str2);
	return (NULL);
}

int main(void)
{
	char *str = "ls";
	char *result = NULL;
	result = pathchecker(str);
	if (result != NULL)
		printf("Success!\n");
	else
		printf("Fail\n");
	free(result);
	return (0);
}

list_p *pathlist(void)
{
	list_p *pathlist;
	char *path;
	char *strp;

	path = _getenv("PATH");
	strp = strtok(path, ":");
	pathlist = createpathlist(strp);
	strp = strtok(NULL, ":");
	while (strp != NULL)
	{
		
		add_node(&pathlist, strp);
		strp = strtok(NULL, ":");
	}
	return (pathlist);
}
list_p *add_node(list_p **head, char *str)
{
	list_p *tmp;
	char *newstr;
	int l;

	/*tmp->str = NULL;*/
	tmp = malloc(sizeof(list_p));
	if (tmp == NULL)
		return (NULL);
	l = _strlen(str);
	l += 1;
	newstr = malloc(sizeof(char) * (l));
	if (newstr == NULL)
	{
		free(tmp);
		return(NULL);
	}
	newstr = _strncpy(newstr, str, l);
	tmp->str = newstr;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}
list_p *createpathlist(char *str)
{
	list_p *tmp;
	char *newstr;
	int l;

	tmp = malloc(sizeof(list_p));
	if (tmp == NULL)
		return (NULL);
	l = _strlen(str);
	newstr = malloc((sizeof(char)) * (l + 1));
	if (newstr == NULL)
	{
		free(tmp);
		return(NULL);
	}
	newstr = _strncpy(newstr, str, l);
	tmp->str = newstr;
	tmp->next = NULL;
	return (tmp);
}
void free_list(list_p *head)
{
	list_p *new;

	while (head != NULL)
	{
		new = head;
		head = head->next;
		free(new->str);
		free(new);
	}
	free(head);
}
