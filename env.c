 #include "holberton.h"

/**
* envFunc - print the environment
* @args: the parsed env string
*
* Return: 1
*/
int envFunc(char **args, linked_l *env, char *buffer)
{
	printList(env);
	freeArgs(args);
	return (1);
}

int setenvFunc(char **args, linked_l *env, char *buffer)
{
	printf("setenv placeholder\n");
	return (1);
}

int unsetenvFunc(char **args, linked_l *env, char *buffer)
{
	printf("unsetenv placeholder\n");
	return (1);
}
