#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 256

void shell(char *);
_Bool isSpace(char c);
unsigned int countWords(char *s);
char **splitString(char *str);
void print_tab(char **tab);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *checkPath(char *input, char *path);
char *_getenv(char *input, char **environ);
void errorHandler(char *f, int n, char *cmd);
unsigned int countDigits(int num);
char *itoa(unsigned int num);
void insertNullByte(char *str, unsigned int index);
void freeArgs(char **args);
void welcome_screen_1(void);
void welcome_screen_2(void);


#endif
