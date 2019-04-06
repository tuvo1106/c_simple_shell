#include "holberton.h"

void shell(char *path)
{
	pid_t f1;
	size_t n = 0;
	char *buffer = NULL;
	char **args;
	int len, check, j, i = 0;
	char *temp;
	_Bool showPrompt = true;

	while (showPrompt)
	{
		i++;
		j = 0;
		write(STDOUT_FILENO, "$ ", 2);
		len = getline(&buffer, &n, stdin);
		if (len < 0)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
			return;
		}
		buffer[len - 1] = 0;
		args = splitString(buffer);
		temp = check_path(args[0], path);
		f1 = fork();
		if (f1 == 0)
		{
			check = (temp)
				? execve(temp, args, NULL)
				: execve(args[0], args, NULL);
			if (check == -1)
			{
				errorHandler("./shell", i, buffer);
				free(buffer);
				while (args[j])
					free(args[j++]);
				free(args);
				exit(0);
			}

		}
		else
		{
			wait(NULL);
			while (args[j])
				free(args[j++]);
			free(args);
		}
	}
	free(buffer);
}

