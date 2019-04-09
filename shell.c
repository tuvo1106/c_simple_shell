#include "holberton.h"

/**
 * shell - simple shell
 */
void shell(void)
{
	register int len, childStatus, builtInStatus, lineCounter = 0;
	pid_t f1;
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
			if (isatty(STDIN_FILENO))
				displayNewLine();
			exit(0);
		}
		insertNullByte(buffer, len - 1);
		args = splitString(buffer);
		if (args == NULL)
			continue;
		builtInStatus = builtIns(args);
		if (builtInStatus == 1)
			continue;
		fullPath = checkPath(args[0], path);
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
	free(buffer);
}

