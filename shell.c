#include "holberton.h"

/**
 * shell - simple shell
 * @PATH: string of $PATH
 * @ENVIRON: array of environ variables
 */
void shell(char *PATH, char **ENVIRON)
{
	register int len, childStatus, lineCounter = 0;
	pid_t f1;
	size_t bufferSize = 0;
	char *buffer = NULL, *fullPath = NULL;
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
		fullPath = checkPath(args[0], PATH);
		f1 = fork();
		if (f1 == 0)
		{
			childStatus = fullPath
				? execve(fullPath, args, ENVIRON)
				: execve(args[0], args, ENVIRON);
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

