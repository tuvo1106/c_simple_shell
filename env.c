#include "holberton.h"

/**
 * envFunc - print the environment
 * @args: the parsed env string
 *
 * Return: 1
 */
int envFunc(config *build)
{
	printList(build->env);
	freeArgs(build->args);
	return (1);
}

int setenvFunc(config *build)
{
	(void)build;
	printf("setenv placeholder\n");
	return (1);
}

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
		printf("Not found\n");
	freeArgs(build->args);
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
