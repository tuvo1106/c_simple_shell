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
	char *PATH = _getenv("PATH", environ);

	signal(SIGINT, sigintHandler);
	(void)ac;
	(void)av;
	shell(PATH, environ);
	return (0);
}
