#include "holberton.h"

/**
* envFunc - print the environment
* @args: the parsed env string
*
* Return: 1
*/
int envFunc(char **args, linke_l env)
{
	linked_l *head = NULL;

	head = generateLinkedList(environ);
	printList(head);
	freeList(&head);
	freeArgs(args);
	return (1);
}


int setenvFunc(char **args, linked_l env)
{
	printf("setenv placeholder\n");
	return(1);
}

int unsetenvFunc(char **args, linked_l env)
{
	printf("unsetenv placeholder\n");
	return (1);
}
