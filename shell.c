#include "holberton.h"

/**
 * shell - simple shell
 * @build: input build
 */
void shell(config *build)
{
	while (true)
	{
		checkAndGetLine(build);
		if (splitString(build) == false)
			continue;
		if (findBuiltIns(build) == true)
			continue;
		checkPath(build);
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
	register int childStatus = 0;
	pid_t f1;

	f1 = fork();
	if (f1 == 0)
	{
		childStatus = execve(build->fullPath, build->args, environ);
		if (childStatus == -1)
		{
			errorHandler(build->lineCounter, build->buffer, NULL);
			freeMembers(build);
			free(build);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		wait(NULL);
		freeArgs(build->args);
		free(build->buffer);
	}
}
