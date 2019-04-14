#include "holberton.h"

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
