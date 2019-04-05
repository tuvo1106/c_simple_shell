#include "holberton.h"

void shell(void)
{
	pid_t f1;
	size_t n = 0;
	char *buffer = NULL;
	char **args;
	int len, check, j, i = 0;
	char *temp;
	char *PATH = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:";

	while (1)
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
		buffer[len - 1] = 0;
		args = splitString(buffer);
		temp = check_path(args[0], PATH);
		f1 = fork();
		if (f1 == 0)
		{
			check = execve(temp, args, NULL);
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

