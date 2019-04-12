#include "holberton.h"

/**
 * expansions - expand variables with $ to its environmental var
 * @build: input build
 */
void expansions(config *build)
{
	register int llIndex, i = 0;
	/* int oldLen, newLen; */
	char *str = NULL, *ptr;
	_Bool found = false;

	while (build->args[i])
	{
		if (build->args[i][0] == '$')
		{
			ptr = strdup(build->args[i]);
			llIndex = searchNode(build->env, ptr);
			if (llIndex >= 0)
			{
				found = true;
				break;
			}
		}
		i++;
	}

	if (found == true)
	{
		str = getNodeAtIndex(build->env, llIndex);
		str += 5;
		build->args[i] = realloc(build->args[i], _strlen(str) + 1);
		strcpy(build->args[i], str);
		free(str - 5);
	} else
	{
		free(str);
	}
}
