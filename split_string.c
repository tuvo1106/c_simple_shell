#include "holberton.h"

/**
 * splitString - splits string into an array of strings
 * separated by spaces
 * @str: input string
 * Return: array of strings
 */
void splitString(config *build)
{
	register unsigned int i = 0;
	char *tok, *cpy;

	if (countWords(build->buffer) == 0)
	{
		build->args = NULL;
		return;
	}
	build->args = malloc((countWords(build->buffer) + 1) * sizeof(char *));
	cpy = _strdup(build->buffer);
	if (!cpy)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	tok = _strtok(cpy, " ");
	while (tok != NULL)
	{
		build->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	build->args[i] = NULL;
	free(cpy);
}

/**
 * countWords - count number of words in a string
 * @str: input string
 * Return: number of words
 */
unsigned int countWords(char *str)
{
	register int words = 0;
	_Bool wordOn = false;

	while (*str)
	{
		if (isSpace(*str) && wordOn)
			wordOn = false;
		else if (!isSpace(*str) && !wordOn)
		{
			wordOn = true;
			words++;
		}
		str++;
	}
	return (words);
}

/**
 * isSpace - determines if char is a space
 * @c: input char
 * Return: true or false
 */
_Bool isSpace(char c)
{
	return (c == ' ');
}
