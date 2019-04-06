#include "holberton.h"

/**
 * shell - simple shell
 * @path: string of $PATH
 */
void shell(char *PATH)
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
			write(STDOUT_FILENO, "$ ", 2);
		len = getline(&buffer, &bufferSize, stdin);
		if (len < 0)
		{
			free(buffer);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		insertNullByte(buffer, len - 1);
		args = splitString(buffer);
		fullPath = checkPath(args[0], PATH);
		f1 = fork();
		if (f1 == 0)
		{
			childStatus = fullPath
				? execve(fullPath, args, NULL)
				: execve(args[0], args, NULL);
			if (childStatus == -1)
			{
				errorHandler("./shell", lineCounter, buffer);
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

