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
	{
		printf("Help command instructions\n");
		freeArgs(build->args);
		free(build->buffer);
		return (0);
	}
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
		errorHandler(build->lineCounter, build->args[1], NULL);
	}
	freeArgs(build->args);
	free(build->buffer);
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
	char str[82] = "exit: exit [n]\n\tExit the shell.\n\n\t";
	char *str2 = "Exit with a status of n, or if n is omitted, 0.\n";

	_strcat(str, str2);
	write(1, str, 82);
	return (0);
}

/**
 * helpEnv - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpEnv(config *build)
{
	(void)build;
	char *str = "env: env\n\tPrint the environment.\n";
	write(1, str, 33);
	return (0);
}

/**
 * helpHistory - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpHistory(config *build)
{
	(void)build;
	char *str = "history: history\n\tNot supported in this version.\n";
	write(1, str, 49);
	return (0);
}

/**
 * helpAlias - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpAlias(config *build)
{
	(void)build;
	char *str = "alias: alias\n\tNot supported in this version.\n";
	write(1, str, 45);
	return (0);
}
