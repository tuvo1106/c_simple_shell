#include "holberton.h"

/**
 * freeMembers - frees build config members
 * @build: input build
 */
void freeMembers(config *build)
{
	if (build->env)
		freeList(build->env);
	if (build->args)
		freeArgs(build->args);
	if (build->buffer)
		free(build->buffer);
}

/**
 * freeArgsAndBuffer - frees args and buffer
 * @build: input build
 */
void freeArgsAndBuffer(config *build)
{
	freeArgs(build->args);
	free(build->buffer);
}

/**
 * freeList - frees a linked list
 * @head: double pointer to head of list
 */
void freeList(linked_l *head)
{
	linked_l *current;
	linked_l *tmp;

	if (!head)
		return;
	current = head;
	while (current)
	{
		tmp = current;
		current = tmp->next;
		free(tmp->string);
		free(tmp);
	}
	head = NULL;
}

/**
 * freeArgs - helper func that frees double pointer arg
 * @args: array of char pointers
 */
void freeArgs(char **args)
{
	register uint i = 0;

	while (args[i])
		free(args[i++]);
	free(args);
}
