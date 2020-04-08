#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

char **strtokarray(char *str);

void _printppid(void);

int _putchar(char c);

void freeptrarray(char **ptr);

char *read_input(void);

#endif
