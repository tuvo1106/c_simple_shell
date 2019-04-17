#include "holberton.h"

/**
 * _strtok - tokenizes strings at delimiter
 * @str: input string
 * @delim: delimiter
 * Return: pointer to start of string
 */

char *_strtok(char *str, char *delim)
{
	static char *lastptr;
	char ch;

	if (str == NULL)
		str = lastptr;
	do {
		ch = *str++;
		if (!ch)
			return (NULL);
	} while (_strchr(delim, ch));
	str--;
	lastptr = str + _strcspn(str, delim);
	if (*lastptr)
		*lastptr++ = 0;
	return (str);
}

/**
 * _strcspn - returns first occurence of any char in
 * second string in first string
 * @string: input string to search
 * @chars: input chars to check
 * Return: pointer to first match
 */
int _strcspn(char *string, char *chars)
{
	char c;
	char *p, *s;

	for (s = string, c = *s; c; s++, c = *s)
		for (p = chars; *p; p++)
			if (c == *p)
				return (s - string);
	return (s - string);
}

/**
 * _strchr - locates a character in a string
 * @s: string to be searched
 * @c: target char
 * Return: pointer to first occurrence of c or NULL if char not found
 */
char *_strchr(char *s, char c)
{
	char x;

	while (true)
	{
		x = *s++;
		if (x == c)
			return (s - 1);
		if (!x)
			return (NULL);
	}
}

