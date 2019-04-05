#include "holberton.h"

void shell(void)
{
	pid_t f1;
	size_t n = 0;
	char *buffer = NULL;
	char **args;
	int len, check, j, i = 0;

	while (1)
	{
		i++;
		write(STDOUT_FILENO, "$ ", 2);
		len = getline(&buffer, &n, stdin);
		if (len < 0)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		buffer[len - 1] = 0;
		args = split(buffer);
		f1 = fork();
		if (f1 == 0)
		{
			check = execve(args[0], args, NULL);
			if (check == -1)
			{
				write(STDOUT_FILENO, "command not found\n", 18);
				free(buffer);
				exit(0);
			}

		}
		else
		{
			wait(NULL);
			j = 0;
			while (args[j])
			{
				free(args[j]);
				j++;
			}
			free(args);
		}
	}
	free(buffer);
}

