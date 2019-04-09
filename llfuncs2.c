#include "holberton.h"

/**
 * searchNode - searches linked list for string and
 * returns index
 * @head: pointer to head of list
 * @str: input string
 * Return: index of node with matching string
 */
int searchNode(linked_l *head, char *str)
{
	register int len, index = 0;
	linked_l *current;
	char *tmp, *ptr;
	
	current = head;
	while (current)
	{
		ptr = _strchr(current->string, '=');
		len = ptr - current->string;
		tmp = malloc(len);
		tmp[len - 1] = 0;
		printf("%s", tmp);
		if (_strcmp(str, tmp) == 0)
		{	free(tmp);
			return (index);
		}
		index++;
		current = current->next;
		free(tmp);
	}
	return (-1);
}

/**
 * generateLinkedList - generates a linked list of environ
 * variables
 * @array: input array of strings
 * Return: head of linked list
 */
linked_l *generateLinkedList(char **array)
{
	register int i;
	linked_l *head;

	head = NULL;
	while (array[i])
	{
		addNodeEnd(&head, array[i]);
		i++;
	}
	return (head);
}
