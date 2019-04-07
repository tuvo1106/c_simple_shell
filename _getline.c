#include "holberton.h"
#include <errno.h>

/**
 * _getline - get line from stream and store in buffer
 * @bufferptr: output buffer
 * @n: size of buffer, if none passed in, function will realloc
 * @stream: input file pointer
 * Return: number of bytes written, or -1 on error
 */
int _getline(char **bufferptr, size_t *n, FILE *stream)
{
	static char buffer[1024];
	char *ptr;
	unsigned int len;
	int r;

	(void)stream;
	if (bufferptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	r = read(STDIN_FILENO, buffer, 1024);
	/*printf("sucessful read...%i\n", r);*/
	if (r <= 0)
		return (-1);
	ptr = _strchr(buffer, '\n');
	if (ptr)
		*++ptr = '\0';
	len = strlen(buffer);
	if ((len + 1) < 1024)
	{
		ptr = _realloc(*bufferptr, 0, len + 1);
		if (ptr == NULL)
			return (-1);
		*bufferptr = ptr;
		*n = len + 1;
	}
	_strcpy(*bufferptr, buffer);
	return (len);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: input pointer
 * @old_size: size of old ptr
 * @new_size: size of new ptr
 * Return: reallocated ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *res = NULL;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
	{
		free(ptr);
		res = malloc(new_size);
		return (res);
	}
	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(new_size);
	_memcpy(res, ptr, old_size);
	free(ptr);
	return (res);
}

/**
 * *_strcpy - copies the string pointed to by src,
 * including the terminating null byte
 * @dest: copied string
 * @src: string to be copied
 * Return: pointer to new copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (ptr);
}

/**
 * _memcpy - copies memory area
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to be copied
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ptr = dest;

	while (n--)
		*dest++ = *src++;
	return (ptr);
}
