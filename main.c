#include "holberton.h"

/**
 * main - entry point for application
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	config build;

	(void)ac;
	signal(SIGINT, sigintHandler);
	configInit(&build);
	build.shellname = av[0];
	shell(&build);
	return (0);
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
	build->shellname = NULL;
	return (build);
}
