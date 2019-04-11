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
	register int i = 0;
	_Bool foundCommand = false;

	if (countArgs(build->args) != 2)
	{
		printf("Invalid arguments\n");
		freeArgs(build->args);
		free(build->buffer);
		return (0);
	}
	while (help_arr[i].command)
	{
		if (_strcmp(build->args[1], help_arr[i].command) == 0)
		{
			foundCommand = true;
			help_arr[i].func(build);
			break;
		}
		i++;
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
	printf("HERE IS HOW TO EXIT...\n");
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
	printf("HERE IS HOW TO ENV...\n");
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
	printf("HERE IS HOW TO HISTORY...\n");
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
	printf("HERE IS HOW TO ALIAS...\n");
	return (0);
}
