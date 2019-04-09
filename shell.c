#include "holberton.h"

/**
 * shell - simple shell
 */
void shell(linked_l *env)
{
	register int len, builtInStatus, lineCounter = 0;
	size_t bufferSize = 0;
	char *buffer = NULL, *fullPath = NULL;
	char *path = _getenv("PATH", environ);
	char **args;

	while (true)
	{
		lineCounter++;
		if (isatty(STDIN_FILENO))
			displayPrompt();
		len = getline(&buffer, &bufferSize, stdin);
		if (len < 0)
		{
			free(buffer);
			freeList(&env);
			if (isatty(STDIN_FILENO))
				displayNewLine();
			exit(0);
		}
		insertNullByte(buffer, len - 1);
		args = splitString(buffer);
		if (args == NULL)
			continue;
		builtInStatus = builtIns(args, env, buffer);
		if (builtInStatus == 1)
			continue;
		fullPath = checkPath(args[0], path);
		forkAndExecute(args, fullPath, buffer, env, lineCounter);
	}
}

void forkAndExecute(char **args, char *fullPath, char *buffer, linked_l *env, int lineCounter)
{	
	pid_t f1;
	int childStatus = 0;

	f1 = fork();
	if (f1 == 0)
	{
		childStatus = fullPath
			? execve(fullPath, args, environ)
			: execve(args[0], args, environ);
		if (childStatus == -1)
		{
			errorHandler(HSH, lineCounter, buffer);
			free(buffer);
			freeList(&env);
			freeArgs(args);
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		freeArgs(args);
	}
}
