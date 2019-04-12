#include "holberton.h"

/**
 * helpCd - instructions on how to exit
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int helpCd(config *build)
{
	(void)build;
	printf("cd placeholder");
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
	char str[186] = "setenv: setenv [var] [value]\n\t";
	char *str2 = "Set or update a variable in the environment.\n\n\t";
	char *str3 = "Creates a variable [var] with [value]. ";
	char *str4 = "If the [var] already exists in the environment, ";
	char *str5 = "the value is updated.\n";

	_strcat(str, str2);
	_strcat(str, str3);
	_strcat(str, str4);
	_strcat(str, str5);
	write(STDOUT_FILENO, str, 186);
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
	char str[116] = "unsetenv: unsetenv [var]\n\t";
	char *str2 = "Unset a variable in the environment.\n\n\t";
	char *str3 = "[var] is an existing variable in the environment.\n";

	_strcat(str, str2);
	_strcat(str, str3);
	write(STDOUT_FILENO, str, 116);
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
	char str[129] = "help: help [built-in]\n\t";
	char *str2 = "Display information about built-in commands.\n\n\t";
	char *str3 = "If [built-in] is not specified, print a list of built-ins.\n";

	_strcat(str, str2);
	_strcat(str, str3);
	write(STDOUT_FILENO, str, 129);
	return (1);
}
