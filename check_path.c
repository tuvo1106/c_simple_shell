#include "holberton.h"

char *check_path(char *input, char *path)
{
	char *copy = _strdup(path);
	char *delim = ":";
	char *buff;
	char *ptr;
	int size;
	struct stat st;

	if (stat(input, &st) == 0)
		return (input);
	ptr = strtok(copy, delim);
	while (ptr != NULL)
	{
		size = _strlen(ptr) + _strlen(input) + 2;
		buff = malloc(size);
		_strcat(buff, ptr);
		_strcat(buff, "/");
		_strcat(buff, input);
		buff[size - 1] = 0;
		if (stat(buff, &st) == 0)
			return (buff);
		free(buff);
		ptr = strtok(NULL, delim);
	}
	return (NULL);
}
