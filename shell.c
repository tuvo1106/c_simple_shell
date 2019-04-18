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
	char *ptr, *ptr2;

	build->args = NULL;
	build->envList = NULL;
	build->lineCounter++;
	if (isatty(STDIN_FILENO))
		displayPrompt();
	len = getline(&build->buffer, &bufferSize, stdin);
	if (len == EOF)
	{
		freeMembers(build);
		if (isatty(STDIN_FILENO))
			displayNewLine();
		if (build->errorStatus)
			exit(build->errorStatus);
		exit(errno);

	}
	ptr = _strchr(build->buffer, '\n');
	ptr2 = _strchr(build->buffer, '\t');
	if (ptr || ptr2)
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
	int status;
	pid_t f1 = fork();

	convertLLtoArr(build);
	if (f1 == -1)
	{
		perror("error\n");
		freeMembers(build);
		freeArgs(build->envList);
		exit(0);
	}
	if (f1 == 0)
	{
		if (execve(build->fullPath, build->args, build->envList) == -1)
		{
			errorHandler(build);
			freeMembers(build);
			freeArgs(build->envList);
			if (errno == ENOENT)
				exit(127);
			if (errno == EACCES)
				exit(126);
			exit(errno);
		}
	} else
	{
		wait(&status);
		if (WIFEXITED(status))
			build->errorStatus = WEXITSTATUS(status);
		freeArgsAndBuffer(build);
		freeArgs(build->envList);
	}
}

/**
 * convertLLtoArr - convert linked list to array
 * @build: input build
 */
void convertLLtoArr(config *build)
{
	register int i = 0;
	size_t count = 0;
	char **envList = NULL;
	linked_l *tmp = build->env;

	count = list_len(build->env);
	envList = malloc(sizeof(char *) * (count + 1));
	if (!envList)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		envList[i] = _strdup(tmp->string);
		tmp = tmp->next;
		i++;
	}
	envList[i] = NULL;
	build->envList = envList;
}
