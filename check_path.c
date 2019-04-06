#include "holberton.h"

char *check_path(char *input, char *path)
{
	static char buff[256];
	char *copy = _strdup(path);
	char *delim = ":";
	char *ptr;
	int size;
	struct stat st;

	if (stat(input, &st) == 0)
		return (input);
	ptr = strtok(copy, delim);
	while (ptr != NULL)
	{

		size = _strlen(ptr) + _strlen(input) + 2;
		_strcat(buff, ptr);
		_strcat(buff, "/");
		_strcat(buff, input);
		buff[size - 1] = 0;
		if (stat(buff, &st) == 0)
		{
			free(copy);
			return (buff);
		}
		buff[0] = 0;
		fflush(stdin);
		ptr = strtok(NULL, delim);
	}
	free(copy);
	return (NULL);
}
