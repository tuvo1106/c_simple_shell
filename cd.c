#include "holberton.h"

/**
 * cdFunc - execute cd builtin
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int cdFunc(config *build)
{
	register uint count = 0;
	_Bool ableToChange = false;

	count = countArgs(build->args);
	if (count == 1)
		ableToChange = cdToHome(build);
	else if (count == 2 && _strcmp(build->args[1], "-") == 0)
		ableToChange = cdToPrevious(build);
	else
		ableToChange = cdToCustom(build);
	if (ableToChange)
		updateEnviron(build);
	freeArgs(build->args);
	free(build->buffer);
	return (1);
}

/**
 * cdToHome - change directory to home
 * @build: input build
 * Return: true on success, false on failure
 */
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

/**
 * cdToPrevious - change directory to previous directory -
 * address is found in OLDPWD env var
 * @build: input build
 * Return: true on success, false on failure
 */
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

/**
 * cdToCustom - change directory to what user inputs in
 * @build: input build
 * Return: true on success, false on failure
 */
_Bool cdToCustom(config *build)
{
	register int changeStatus;

	changeStatus = chdir(build->args[1]);
	if (changeStatus == -1)
	{
		errno = EBADCD;
		errorHandler(build->lineCounter, build->args[0], build->args[1]);
		return (false);
	}
	return (true);
}

/**
 * updateEnviron - change environmental variables
 * @build: input build
 * Return: true on success false on failure
 */
_Bool updateEnviron(config *build)
{
	register int index;

	index = updateOld(build);
	if (index > -1)
		return (updateCur(build, index));
	return (false);
}

