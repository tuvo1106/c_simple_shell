#include "holberton.h"

/**
 * shell - simple shell
 * @build: input build
 */
void shell(config *build)
{
	register int builtInStatus;

	while (true)
	{
		checkAndGetLine(build);
		build->args = splitString(build->buffer);
		if (build->args == NULL)
		{
			free(build->buffer);
			continue;
		}
		builtInStatus = builtIns(build);
		if (builtInStatus == true)
			continue;
		build->fullPath = checkPath(build->args[0], build->path);
		forkAndExecute(build);
	}
}

/**
 * checkAndGetLine - check stdin and retrieves next line; handles
 * prompt display
 * @build: input build
 */
void checkAndGetLine(config *build)
{
	register int len;
	size_t bufferSize = 0;

	build->args = NULL;
	build->lineCounter++;
	if (isatty(STDIN_FILENO))
		displayPrompt();
	len = getline(&build->buffer, &bufferSize, stdin);
	if (len < 0)
	{
		freeMembers(build);
		free(build);
		if (isatty(STDIN_FILENO))
			displayNewLine();
		exit(0);
	}
	insertNullByte(build->buffer, len - 1);
	stripComments(build->buffer);
}

/**
 * stripComments - remove comments from input string
 * @str: input string
 * Return: length of remaining string
 */
void stripComments(char *str)
{
	register int i = 0;

	while (str[i])
	{
		if (str[i] == '#')
		{
			insertNullByte(str, i);
			break;
		}
		i++;
	}
}

/**
 * forkAndExecute - fork current build and execute processes
 * @build: input build
 */
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
			errorHandler(build->lineCounter, build->buffer, NULL);
			freeMembers(build);
			free(build);
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		freeArgs(build->args);
		free(build->buffer);
	}
}
