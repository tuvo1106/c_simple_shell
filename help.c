#include "holberton.h"

/**
 * helpFunc - retrieves instruction on how to use builtin
 * @build: input build
 * Return: 1 if success, 0 on failure
 */
int helpFunc(config *build)
{
	type_b help_arr[] = {
		{"exit", helpExit},
		{"env", helpEnv},
		{"history", helpHistory},
		{"alias", helpAlias},
		{"cd", helpCd},
		{"setenv", helpSetenv},
		{"unsetenv", helpUnsetenv},
		{"help", helpHelp},
		{NULL, NULL}
	};
	register int i = 0, j = 1, argCount = countArgs(build->args);
	_Bool foundCommand = false;

	if (argCount == 1)
		return (displayHelpMenu());
	while (j < argCount)
	{
		i = 0;
		while (help_arr[i].command)
		{
			if (_strcmp(build->args[j], help_arr[i].command) == 0)
			{
				foundCommand = true;
				help_arr[i].func(build);
				break;
			}
			i++;
		}
		j++;
	}
	if (foundCommand == false)
	{
		errno = ENOBUILTIN;
		errorHandler(build->lineCounter, build->args[1], NULL);
	}
	return (1);
}

/**
 * displayHelpMenu - displays available help options
 * Return: 1 on success, 0 on failure
 */
int displayHelpMenu(void)
{
	char str[] = "Type help [built-in]\n\nIncluded built-ins:";
	char str2[] = "\n\n\texit\n\tenv\n\tcd\n\tsetenv\n\tunsetenv\n\thelp\n";

	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, str2, _strlen(str2));
	return (1);
}


/**
 * helpExit - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpExit(config *build)
{
	(void)build;
	char str[] = "exit: exit [n]\n\tExit the shell.\n\n\t";
	char str2[] = "Exit with a status of n, or if n is omitted, 0.\n";

	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, str2, _strlen(str2));
	return (1);
}

/**
 * helpEnv - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpEnv(config *build)
{
	(void)build;
	char str[] = "env: env\n\tPrint the environment.\n";

	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * helpHistory - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpHistory(config *build)
{
	(void)build;
	char str[] = "history: history\n\tNot supported in this version.\n";

	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
