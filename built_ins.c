#include "holberton.h"
/**
* builtIns - find the right built in to use
* @args: parsed strings
*
* Return: 1 if found, 0 if not found
*/
int builtIns(char **args, linked_l env)
{
	type_b getBuiltIns[] = {
	{"exit", exitFunc},
	{"env", envFunc},
	{"history", historyFunc},
	{"alias", aliasFunc},
	{"cd", cdFunc},
	{"setenv", setenvFunc},
	{"unsetenv", unsetenvFunc},
	{NULL, NULL}
	};

	int index = 0;

	while (getBuiltIns[index].command)
	{
		if (_strcmp(args[0], getBuiltIns[index].command) == 0)
		{
			getBuiltIns[index].func(args, env);
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
int exitFunc(char **args, linked_l env)
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
int historyFunc(char **args, linked_l env)
{
	printf("history placeholder\n");
	return (1);
}

int aliasFunc(char **args, linked_l env)
{
	printf("alias placeholder\n");
	return (1);
}

