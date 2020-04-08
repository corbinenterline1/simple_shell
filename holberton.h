#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys.stat.h>
#include <unistd.h>
#include <fcntl.h>
int _putchar(char c);
char *read_input(char *s);
char **strtokarray(char *str);
void freeptrarray(char **ptr);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int execute_input(char *argv[]);
#endif /*HOLBERTON_H*/
