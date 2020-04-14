#include "holberton.h"

/**
 * pathchecker - Checks the path list for said argument
 * with each directory + '/' prepended to the argument.
 * @head: double pointer to head of singly-linked list containing PATH
 * @arg: argument to test
 * Return: Successful prepended string, or NULL if failed
 */
char *pathchecker(list_p **head, char *arg)
{
	struct stat statty;
	char *slas = "/";
	char *str = NULL, *slarg = NULL, *tester = NULL;
	list_p *cpy;

	cpy = *head;

	slarg = str_concat(slas, arg);
	while (cpy)
	{
		str = cpy->str;
		tester = str_concat(str, slarg);
		if (stat(tester, &statty) == 0)
		{
			free(slarg);
			return (tester);
		}
		else
		{
		free(tester);
		cpy = cpy->next;
		}
	}
	free(slarg);
	return (NULL);
}

/**
 * pathlist - Creates a singly linked list of each directory from PATH
 * Return: Pointer to head of linked list containing split up PATH
 */
list_p *pathlist(void)
{
	list_p *pather;
	char *path = NULL;
	char *strp = NULL;

	path = _getenv("PATH");
	strp = strtok(path, ":");
	pather = createpathlist(strp);
	strp = strtok(NULL, ":");
	while (strp != NULL)
	{

		add_node(&pather, strp);
		strp = strtok(NULL, ":");
	}
	return (pather);
}

/**
 * add_node - Adds new node at head of linked list
 * @head: double pointer to head of linked list
 * @str: string to add in new node
 * Return: new pointer to head, or NULL if failed
 */
list_p *add_node(list_p **head, char *str)
{
	list_p *tmp;
	char *newstr = NULL;
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
		return (NULL);
	}
	newstr = _strncpy(newstr, str, l);
	tmp->str = newstr;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

/**
 * createpathlist - creates new singly linked list from first dir of PATH
 * @str: input string (in this instance, first directory of PATH)
 * Return: pointer to head of linked list, or NULL if fail
 */
list_p *createpathlist(char *str)
{
	list_p *tmp;
	char *newstr = NULL;
	int l;

	tmp = malloc(sizeof(list_p));
	if (tmp == NULL)
		return (NULL);
	l = _strlen(str);
	newstr = malloc((sizeof(char)) * (l + 1));
	if (newstr == NULL)
	{
		free(tmp);
		return (NULL);
	}
	newstr = _strncpy(newstr, str, l);
	tmp->str = newstr;
	tmp->next = NULL;
	return (tmp);
}

/**
 * free_list - Frees up linked list & all node strings
 * @head: pointer to head of list
 */
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
