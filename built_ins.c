#include "holberton.h"


int builtIns(char **args)
{
	type_b getBuiltIns[] = {
	{"exit", exitFunc},
	{"env", envFunc},
	{NULL, NULL}
	};

	int index = 0;

	while (getBuiltIns[index].command)
	{
		if (_strcmp(args[0], getBuiltIns[index].command) == 0)
		{	
			getBuiltIns[index].func(args);
			return (1);
		}
		index++;
	}
	return (0);
}

int exitFunc(char **args)
{
	printf("exit: success\n");	
	return (1);
}

int envFunc(char **args)
{
	printf("env: success\n");
	return (1);
}
