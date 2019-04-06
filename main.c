#include "holberton.h"

int main(int ac, char **av, char **environ)
{
	char *path;
	path = _getenv("PATH", environ);
	shell(path);
	return (0);
}
