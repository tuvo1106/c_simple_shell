#include "holberton.h"

/**
 * main - entry point for application
 * Return: 0 on success
 */
int main(void)
{
	config *build;

	signal(SIGINT, sigintHandler);
	build = malloc(sizeof(config));
	if (!build)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	configInit(build);
	shell(build);
	return (EXIT_SUCCESS);
}

/**
 * configInit - initialize member values for config struct
 * @build: input build
 * Return: build with initialized members
 */
config *configInit(config *build)
{
	build->env = generateLinkedList(environ);
	build->envList = NULL;
	build->args = NULL;
	build->buffer = NULL;
	build->path = _getenv("PATH", environ);
	build->fullPath = NULL;
	build->lineCounter = 0;
	return (build);
}
