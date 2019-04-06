#include "holberton.h"

/**
 * shell - simple shell
 * @path: string of $PATH
 */
void shell(char *path)
{
	register int len, check, i = 0;
	pid_t f1;
	size_t n = 0;
	char *buffer = NULL, *fullPath = NULL;
	char **args;

	while (true)
	{
		i++;
		write(STDOUT_FILENO, "$ ", 2);
		len = getline(&buffer, &n, stdin);
		if (len < 0)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
			return;
		}
		insertNullByte(buffer, len - 1);
		args = splitString(buffer);
		fullPath = check_path(args[0], path);
		f1 = fork();
		if (f1 == 0)
		{
			check = (fullPath)
				? execve(fullPath, args, NULL)
				: execve(args[0], args, NULL);
			if (check == -1)
			{
				errorHandler("./shell", i, buffer);
				free(buffer);
				freeArgs(args);
				exit(0);
			}

		}
		else
		{
			wait(NULL);
			freeArgs(args);
		}
	}
	free(buffer);
}

