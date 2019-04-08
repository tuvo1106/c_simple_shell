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
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define BUFSIZE 256
#define HSH "./hsh"

/**
 * struct builtInCommands - commands and functions associated with it
 * @command: input command
 * @func: output function
 */
typedef struct builtInCommands
{
	char *command;
	int (*func)(char **args);
} type_b;

int builtIns(char **args);
int exitFunc(char **args);
int envFunc(char **args);
/* shell */
void shell(char *, char **);

/* _getenv */
char *_getenv(char *input, char **environ);

/* error_handler */
void errorHandler(char *f, int n, char *cmd);
unsigned int countDigits(int num);
char *itoa(unsigned int num);

/* shell_helpers */
void freeArgs(char **args);
void insertNullByte(char *str, unsigned int index);
void displayPrompt(void);
void displayNewLine(void);
void sigintHandler(int sigint);

/* check_path */
char *checkPath(char *input, char *path);

/* split_string */
char **splitString(char *str);
unsigned int countWords(char *s);
_Bool isSpace(char c);

/* string_helpers1 */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/* string_helpers2 */
char *_strtok(char *str, char *delim);
int _strcspn(char *string, char *chars);
char *_strchr(char *s, char c);

/* welcome */
void welcome_screen_1(void);
void welcome_screen_2(void);

/* _getline */
int _getline(char **bufferptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
