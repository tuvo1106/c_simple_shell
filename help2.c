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
	return (0);
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
	char *str4 = "If the [var] already exists in the environment, the value is updated.\n";
	
	_strcat(str, str2);
	_strcat(str, str3);
	_strcat(str, str4);
	write(1, str, 186);
	return (0);
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

	_strcat(str,str2);
	_strcat(str,str3);
	write(1, str, 116);
	return (0);
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
	char *str3 ="If [built-in] is not specified, print a list of built-ins.\n";

	_strcat(str, str2);
	_strcat(str, str3);
	write(1, str, 129);
	return (0);
}
