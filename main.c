#include "holberton.h"

/**
 * main - entry point for application
 * Return: 0 on success
 */
int main(void)
{
	signal(SIGINT, sigintHandler);
	shell();
	return (EXIT_SUCCESS);
}
