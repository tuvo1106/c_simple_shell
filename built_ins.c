#include "holberton.h"
/**
* builtIns - find the right built in to use
* @args: parsed strings
*
* Return: 1 if found, 0 if not found
*/
int builtIns(char **args)
{
	type_b getBuiltIns[] = {
	{"exit", exitFunc},
	{"env", envFunc},
	{NULL, NULL}
	};

	int index = 0;

	while (getBuiltIns[index].command)
	{
		if (_strcmp(args[0], getBuiltIns[index].command) == 0)
		{
			getBuiltIns[index].func(args);
			return (1);
		}
		index++;
	}
	return (0);
}

/**
* exitFunc - exit.
* @args: the parsed exit string
*
* Return: 1
*/
int exitFunc(char **args)
{
	int argCount, exitStatus;

	argCount = countArgs(args);
	freeArgs(args);
	if (argCount == 1)
		exit(0);
	else if (argCount > 1)
	{
		/* check for valid string */
		exitStatus = _atoi(args[1]);
		exit(exitStatus);
	}
	return (0);
}
/**
* envFunc - print the environment
* @args: the parsed env string
*
* Return: 1
*/
int envFunc(char **args)
{
	linked_l *head = NULL;

	head = generateLinkedList(environ);
	printList(head);
	freeList(&head);
	freeArgs(args);
	return (1);
}
