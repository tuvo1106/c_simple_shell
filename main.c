#include "holberton.h"

/**
 * main - entry point for application
 * @ac: argument count
 * @av: argument vector
 * @environ: pointer to environmental constants
 * Return: 0 on success
 */
int main(int ac, char **av, char **environ)
{
	char *path = _getenv("PATH", environ);

	shell(path);
	return (0);
}
