#include "holberton.h"

/**
 * shell - simple shell
 */
void shell(config *build)
{
	register int len, builtInStatus;
	size_t bufferSize = 0;

	while (true)
	{
		build->args = NULL;
		build->lineCounter++;
		if (isatty(STDIN_FILENO))
			displayPrompt();
		len = getline(&build->buffer, &bufferSize, stdin);
		if (len < 0)
		{
			freeAlltheThings(build);
			free(build);
			if (isatty(STDIN_FILENO))
				displayNewLine();
			exit(0);
		}
		insertNullByte(build->buffer, len - 1);
		build->args = splitString(build->buffer);
		if (build->args == NULL)
			continue;
		builtInStatus = builtIns(build);
		if (builtInStatus == 1)
			continue;
		build->fullPath = checkPath(build->args[0], build->path);
		forkAndExecute(build);
	}
}

void forkAndExecute(config *build)
{
	pid_t f1;
	int childStatus = 0;

	f1 = fork();
	if (f1 == 0)
	{
		childStatus = build->fullPath
			? execve(build->fullPath, build->args, environ)
			: execve(build->args[0], build->args, environ);
		if (childStatus == -1)
		{
			errorHandler(HSH, build->lineCounter, build->buffer);
			freeAlltheThings(build);
			free(build);
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		freeArgs(build->args);
	}
}
