#include "holberton.h"

/**
 * cdFunc - execute cd builtin
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int cdFunc(config *build)
{
	register uint count = 0;
	int pwdIndex = 0, index = 0, len = 0;
	_Bool ableToChange = true;
	char *current = NULL;
	static char old[BUFSIZE], tmp[BUFSIZE], cwd[BUFSIZE];

	count = countArgs(build->args);
	if (count == 1)
		ableToChange = cdToHome(build);
	else if ((count == 2) && (_strcmp(build->args[1], "-") == 0))
		ableToChange = cdToPrevious(build);
	else if (count > 1)
		ableToChange = cdToCustom(build);
	if (ableToChange)
	{
		pwdIndex = searchNode(build->env, "PWD");
		current = getNodeAtIndex(build->env, pwdIndex);
		_strcat(old, "OLD");
		_strcat(old, current);
		insertNullByte(old, _strlen(current) + 4);
		index = searchNode(build->env, "OLDPWD");
		deleteNodeAtIndex(&build->env, index);
		addNodeAtIndex(&build->env, index, old);
		deleteNodeAtIndex(&build->env, pwdIndex);
		getcwd(tmp, BUFSIZE);
		_strcat(cwd, "PWD=");
		_strcat(cwd, tmp);
		addNodeAtIndex(&build->env, pwdIndex, cwd);
	}
	free(current);
	freeArgs(build->args);
	free(build->buffer);
	insertNullByte(old, 0);
	insertNullByte(tmp, 0);
	insertNullByte(cwd, 0);
	return (1);
}

_Bool cdToHome(config *build)
{
	register int index;
	char *str, *ptr;

	index = searchNode(build->env, "HOME");
	if (index == -1)
	{
		perror("No $HOME directory");
		return (false);
	}
	str = getNodeAtIndex(build->env, index);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	free(str);
	return (true);
}

_Bool cdToPrevious(config *build)
{
	register int index;
	char *str, *ptr;

	index = searchNode(build->env, "OLDPWD");
	if (index == -1)
	{
		perror("No $OLDPWD directory");
		return (false);
	}
	str = getNodeAtIndex(build->env, index);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	free(str);
	return (true);
}

_Bool cdToCustom(config *build)
{
	int changeStatus;

	changeStatus = chdir(build->args[1]);
	if (changeStatus == -1)
	{
		errno = EBADCD;
		errorHandler(build->lineCounter, build->args[0], build->args[1]);
		return (false);
	}
	return (true);
}


