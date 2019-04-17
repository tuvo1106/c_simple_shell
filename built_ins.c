#include "holberton.h"

/**
 * findBuiltIns - validates if command is builtin and executes
 * @build: input build
 * Return: true if found, false if not
 */
_Bool findBuiltIns(config *build)
{
	register int i = 0;
	type_b getBuiltIns[] = {
		{"exit", exitFunc},
		{"env", envFunc},
		{"history", historyFunc},
		{"alias", aliasFunc},
		{"cd", cdFunc},
		{"setenv", setenvFunc},
		{"unsetenv", unsetenvFunc},
		{"help", helpFunc},
		{NULL, NULL}
	};

	while (getBuiltIns[i].command)
	{
		if (_strcmp(build->args[0], getBuiltIns[i].command) == 0)
		{
			getBuiltIns[i].func(build);
			freeArgsAndBuffer(build);
			return (true);
		}
		i++;
	}
	return (false);
}

/**
 * exitFunc - exits the application
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int exitFunc(config *build)
{
	register int argCount, exitStatus;

	argCount = countArgs(build->args);
	if (argCount == 1)
	{
		freeMembers(build);
		if (build->errorStatus)
			exit(build->errorStatus);
		exit(EXIT_SUCCESS);
	}
	else if (argCount > 1)
	{
		exitStatus = _atoi(build->args[1]);
		if (exitStatus == -1)
		{
			errno = EILLEGAL;
			build->errorStatus = 2;
			errorHandler(build);
			return (0);
		}
		freeMembers(build);
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
	char *str = "Currently in development\n";

	(void)build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * aliasFunc - displays local aliases
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int aliasFunc(config *build)
{
	char *str = "Currently in development\n";

	(void)build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
