#include "holberton.h"

/**
 * main - entry point for application
 * Return: 0 on success
 */
int main(void)
{
	linked_l *env;

	signal(SIGINT, sigintHandler);
	env = generateLinkedList(environ);
	shell(env);
	return (EXIT_SUCCESS);
}
