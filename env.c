 #include "holberton.h"

/**
* envFunc - print the environment
* @args: the parsed env string
*
* Return: 1
*/
int envFunc(char **args, linked_l *env, char *buffer)
{
	printList(env);
	freeArgs(args);
	return (1);
}

int setenvFunc(char **args, linked_l *env, char *buffer)
{
	printf("setenv placeholder\n");
	return (1);
}

int unsetenvFunc(char **args, linked_l *env, char *buffer)
{
	int foundVar, i = 1;

	printf("unsetenv placeholder\n");
	
	while (args[i])
	{
		if (_isalpha(args[i][0]) || args[i][0] == '_')
		{	
			foundVar = searchNode(env, args[i]);
			if (foundVar > -1)
				deleteNodeAtIndex(&env, foundVar);
		}
		else
		{		
			printf("bad var\n");
		}
		i++;
	}	
		return (1);
}

#include "holberton.h"

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
