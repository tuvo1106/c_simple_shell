#include "holberton.h"

/**
 * helpAlias - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpAlias(config *build)
{
	(void)build;
	char str[] = "alias: alias\n\tNot supported in this version.\n";

	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * helpCd - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpCd(config *build)
{
	(void)build;
	char str[] = "cd: cd [destination]\n\t";
	char str2[] = "Change directory to target destination.\n\t";
	char str3[] = "If [destination] is ommitted, user will taken to home.\n\t";
	char str4[] = "If \"-\" is used as second argument, user will be taken to ";
	char str5[] = "last directory.\n";

	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, str2, _strlen(str2));
	write(STDOUT_FILENO, str3, _strlen(str3));
	write(STDOUT_FILENO, str4, _strlen(str4));
	write(STDOUT_FILENO, str5, _strlen(str5));
	return (1);
}

/**
 * helpSetenv - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpSetenv(config *build)
{
	(void)build;
	char str[] = "setenv: setenv [var] [value]\n\t";
	char str2[] = "Set or update a variable in the environment.\n\n\t";
	char str3[] = "Creates a variable [var] with [value]. ";
	char str4[] = "If the [var] already exists in the environment, ";
	char str5[] = "the value is updated.\n";

	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, str2, _strlen(str2));
	write(STDOUT_FILENO, str3, _strlen(str3));
	write(STDOUT_FILENO, str4, _strlen(str4));
	write(STDOUT_FILENO, str5, _strlen(str5));
	return (1);
}

/**
 * helpUnsetenv - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpUnsetenv(config *build)
{
	(void)build;
	char str[] = "unsetenv: unsetenv [var]\n\t";
	char str2[] = "Unset a variable in the environment.\n\n\t";
	char str3[] = "[var] is an existing variable in the environment.\n";

	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, str2, _strlen(str2));
	write(STDOUT_FILENO, str3, _strlen(str3));
	return (1);
}

/**
 * helpHelp - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpHelp(config *build)
{
	(void)build;
	char str[] = "help: help [built-in]\n\t";
	char str2[] = "Display information about built-in commands.\n\n\t";
	char str3[] = "If [built-in] is not specified, print a list of built-ins.\n";

	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, str2, _strlen(str2));
	write(STDOUT_FILENO, str3, _strlen(str3));
	return (1);
}
