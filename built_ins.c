#include "holberton.h"
/**
* builtIns - find the right built in to use
* @build: input build
*
* Return: 1 if found, 0 if not found
*/
int builtIns(config *build)
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
			return (1);
		}
		index++;
	}
	return (0);
}

/**
* exitFunc - exits the applciation
* @build: input build
*
* Return: 1 on success
*/
int exitFunc(config *build)
{
	int argCount, exitStatus;
	_Bool illegalName = true;

	argCount = countArgs(build->args);
	freeMembers(build);
	free(build);
	if (argCount == 1)
		exit(0);
	else if (argCount > 1)
	{
		/* check for valid string */
		/* placeholder logic */
		if (illegalName == true)
		{
			errorHandler(build->lineCounter, build->buffer, build->args[1]);
			return (0);
		}
		exitStatus = _atoi(build->args[1]);
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
 * Return: 1 on success
 */
int aliasFunc(config *build)
{
	(void)build;
	printf("alias placeholder\n");
	return (1);
}

