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
		varExpansions(build);
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
 * varExpansions - expands env variable expansions for $$ and $?
 * @build: config build
 */
void varExpansions(config *build)
{
	register int i = 0, pLen, eLen;
	pid_t ppid = getppid();
	char *ppidStr = itoa((unsigned int)ppid);
	char *errStr = itoa((unsigned int)errno);
	char *ppidCopy, *errCopy;

	pLen = _strlen(ppidStr);
	eLen = _strlen(errStr);
	while (build->args[i])
	{
		if (strcmp(build->args[i], "$$") == 0)
		{
			ppidCopy = strdup(build->args[i]);
			ppidCopy = _realloc(ppidCopy, 2, pLen + 1);
			_strcpy(ppidCopy, ppidStr);
			free(build->args[i]);
			build->args[i] = ppidCopy;
		} else if (strcmp(build->args[i], "$?") == 0)
		{
			errCopy = strdup(build->args[i]);
			errCopy = _realloc(errCopy, 2, eLen + 1);
			_strcpy(errCopy, errStr);
			free(build->args[i]);
			build->args[i] = errCopy;
		}
		i++;
	}
	free(errStr);
	free(ppidStr);
}


/**
 * forkAndExecute - fork current build and execute processes
 * @build: input build
 */
void forkAndExecute(config *build)
{
	pid_t f1 = fork();

	if (f1 == 0)
	{
		if (execve(build->fullPath, build->args, environ) == -1)
		{
			errorHandler(build->lineCounter, build->buffer, NULL);
			freeMembers(build);
			free(build);
			exit(EXIT_SUCCESS);
		}
	} else
	{
		wait(NULL);
		freeArgs(build->args);
		free(build->buffer);
	}
}
