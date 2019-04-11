#include "holberton.h"

/**
 * findBuiltIns - find the right built in to use
 * @build: input build
 * Return: 1 if found, 0 if not found
 */
_Bool findBuiltIns(config *build)
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

	register int index = 0;

	while (getBuiltIns[index].command)
	{
		if (_strcmp(build->args[0], getBuiltIns[index].command) == 0)
		{
			getBuiltIns[index].func(build);
			return (true);
		}
		index++;
	}
	return (false);
}

/**
 * exitFunc - exits the applciation
 * @build: input build
 * Return: 1 on success
 */
int exitFunc(config *build)
{
	int argCount, exitStatus;

	argCount = countArgs(build->args);
	if (argCount == 1)
	{
		freeMembers(build);
		free(build);
		exit(0);
	}
	else if (argCount > 1)
	{
		exitStatus = _atoi(build->args[1]);
		if (exitStatus == -1)
		{
			errno = EILLEGAL;
			errorHandler(build->lineCounter, build->args[0], build->args[1]);
			freeArgs(build->args);
			free(build->buffer);
			return (0);
		}
		freeMembers(build);
		free(build);
		exit(exitStatus);
	}
	return (1);
}

/**
 * historyFunc - displays command history
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int historyFunc(config *build)
{
	(void)build;
	printf("history placeholder\n");
	return (1);
}

/**
 * aliasFunc - displays local aliases
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int aliasFunc(config *build)
{
	(void)build;
	printf("alias placeholder\n");
	return (1);
}

