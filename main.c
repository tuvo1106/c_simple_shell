#include "holberton.h"

/**
 * main - entry point for application
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	config build;

	(void)ac;
	signal(SIGINT, sigintHandler);
	configInit(&build);
	build.shellName = av[0];
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
	build->shellName = NULL;
	build->errorStatus = 0;
	return (build);
}
