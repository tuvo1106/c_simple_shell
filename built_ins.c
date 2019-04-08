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
	printf("exit: success\n");
	return (1);
}
/**
* envFunc - print the environment
* @args: the parsed env string
*
* Return: 1
*/
int envFunc(char **args)
{
	printf("env: success\n");
	return (1);
}
