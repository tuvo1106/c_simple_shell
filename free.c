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

