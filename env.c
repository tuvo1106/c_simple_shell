#include "holberton.h"

/**
 * envFunc - print all the environment variables
 * @build: input build
 * Return: 1 on success
 */
int envFunc(config *build)
{
	printList(build->env);
	freeArgs(build->args);
	free(build->buffer);
	return (1);
}

/**
 * setenvFunc - adds env variable if it does not exist;
 * modify env variable if it does
 * @build: input build
 * Return: 1 on success
 */
int setenvFunc(config *build)
{
	(void)build;
	printf("setenv placeholder\n");
	return (1);
}

/**
 * unsetenvFunc - deletes env variable if exists;
 * will only accept valid variables names
 * @build: input build
 * Return: 1 on success
 */
int unsetenvFunc(config *build)
{
	register int foundVar, i = 1;
	_Bool foundMatch = false;

	while (build->args[i])
	{
		if (_isalpha(build->args[i][0]) || build->args[i][0] == '_')
		{
			foundVar = searchNode(build->env, build->args[i]);
			if (foundVar > -1)
			{
				deleteNodeAtIndex(&build->env, foundVar);
				foundMatch = true;
			}
		}
		i++;
	}
	if (foundMatch == false)
	{
		/* Call error handler */
		printf("Not found\n");
	}
	freeArgs(build->args);
	free(build->buffer);
	return (1);
}

/**
 * _isalpha - checks if c is an alphabetic character
 * @c: potential alphabetical value
 * Return: if c is a letter, returns 1. Otherwise, return 0.
 */
int _isalpha(int c)
{
	if (c > 64 && c < 91)
		return (1);
	else if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}
