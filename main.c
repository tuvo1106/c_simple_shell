#include "holberton.h"

/**
 * main - entry point for application
 * Return: 0 on success
 */
int main(void)
{
	config *build;

	build = malloc(sizeof(config));
	signal(SIGINT, sigintHandler);
	build->env = generateLinkedList(environ);
	build->args = NULL;
	build->buffer = NULL;
	build->path = _getenv("PATH", environ);
	build->fullPath = NULL;
	build->lineCounter = 0;
	shell(build);
	return (EXIT_SUCCESS);
}
