#include "holberton.h"

/**
 * splitString - splits string into an array of strings
 * separated by spaces
 * @str: input string
 * Return: array of strings
 */
char **splitString(char *str)
{
	register unsigned int i = 0;
	char *tok, *cpy;
	char **res;

	if (countWords(str) == 0)
		return (NULL);
	res = malloc((countWords(str) + 1) * sizeof(char *));
	if (!res)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	cpy = _strdup(str);
	if (!cpy)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	tok = _strtok(cpy, " ");
	while (tok != NULL)
	{
		res[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	res[i] = NULL;
	free(cpy);
	return (res);
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
