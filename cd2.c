#include "holberton.h"

/**
 * updateOld - updates OLDPWD to current PWD
 * @build: input build
 * Return: index in linked list of PWD on success -
 * If PWD or OLDPWD does not exist in environ vars,
 * return -1
 */
int updateOld(config *build)
{
	register int pwdIndex = 0, index = 0;
	static char old[BUFSIZE];
	char *current = NULL;

	_strcat(old, "OLD");
	pwdIndex = searchNode(build->env, "PWD");
	if (pwdIndex == -1)
	{
		return (-1);
	}
	current = getNodeAtIndex(build->env, pwdIndex);
	_strcat(old, current);
	insertNullByte(old, _strlen(current) + 4);
	free(current);
	index = searchNode(build->env, "OLDPWD");
	if (index == -1)
	{
		return (-1);
	}
	deleteNodeAtIndex(&build->env, index);
	addNodeAtIndex(&build->env, index, old);
	insertNullByte(old, 0);
	return (pwdIndex);
}

/**
 * updateCur - updates PWD to accurately reflect current directory
 * @build: input build
 * @index: index in linked list of where to insert PWD env var
 * Return: true on success, false on failure
 */
_Bool updateCur(config *build, int index)
{
	static char tmp[BUFSIZE], cwd[BUFSIZE];

	getcwd(tmp, BUFSIZE);
	_strcat(cwd, "PWD=");
	_strcat(cwd, tmp);
	if (index > -1)
	{
		deleteNodeAtIndex(&build->env, index);
		addNodeAtIndex(&build->env, index, cwd);
	} else
		addNodeAtIndex(&build->env, 0, cwd);
	insertNullByte(tmp, 0);
	insertNullByte(cwd, 0);
	return (true);
}
