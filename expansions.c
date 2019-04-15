#include "holberton.h"

/**
 * checkExpansions - helper function that delegates
 * environmental and special variable expansions
 * @build: input build
 */
void checkExpansions(config *build)
{
	envExpansions(build);
	varExpansions(build);
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
		if (_strcmp(build->args[i], "$$") == 0)
		{
			ppidCopy = _strdup(build->args[i]);
			ppidCopy = _realloc(ppidCopy, _strlen(ppidCopy), pLen + 1);
			_strcpy(ppidCopy, ppidStr);
			free(build->args[i]);
			build->args[i] = ppidCopy;
		} else if (_strcmp(build->args[i], "$?") == 0)
		{
			errCopy = _strdup(build->args[i]);
			errCopy = _realloc(errCopy, _strlen(errCopy), eLen + 1);
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
 * envExpansions - expand variables with $ to its environmental var
 * @build: input build
 */
void envExpansions(config *build)
{
	register int oldLen, llIndex, i = 0;
	char *str = NULL, *ptr = NULL;
	_Bool found = false;

	while (build->args[i])
	{
		if (build->args[i][0] == '$')
		{
			ptr = _strdup(build->args[i]);
			ptr++;
			oldLen = _strlen(ptr);
			llIndex = searchNode(build->env, ptr);
			free(--ptr);
			if (llIndex >= 0)
			{
				found = true;
				break;
			}
		}
		i++;
	}
	if (found)
	{
		str = getNodeAtIndex(build->env, llIndex);
		str += oldLen + 1;
		build->args[i] = _realloc(build->args[i], oldLen, _strlen(str) + 1);
		_strcpy(build->args[i], str);
		free(str - oldLen - 1);
	}
}
