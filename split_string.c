#include "holberton.h"

_Bool isSpace(char c)
{
	return (c == ' ');
}

unsigned int countWords(char *s)
{
	int wordOn = false;
	int words = 0;

	while (*s)
	{
		if (isSpace(*s) && wordOn)
			wordOn = false;
		else if (!isSpace(*s) && !wordOn)
		{
			wordOn = true;
			words++;
		}
		s++;
	}
	return (words);
}

char **splitString(char *str)
{
	char *cpy = _strdup(str);
	char **res;
	char *tok;
	unsigned int i = 0;

	res = malloc((countWords(str) + 1) * 8);
	if (!res)
	{
		free(cpy);
		return (NULL);
	}
	tok = strtok(cpy, " ");

	while (tok != NULL)
	{
		res[i] = _strdup(tok);
		tok = strtok(NULL, " ");
		i++;
	}
	res[i] = NULL;
	free(cpy);
	return (res);
}
