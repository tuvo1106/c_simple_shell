#include "holberton.h"

/**
 * searchNode - searches linked list for string and
 * returns index
 * @head: pointer to head of list
 * @str: input string
 * Return: index of node with matching string
 */
unsigned int searchNode(linked_l *head, char *str)
{
	register uint index = 0;
	linked_l *current;
	char *tok;

	current = head;
	while (current)
	{
		tok = _strtok(current->string, "=");
		if (_strcmp(str, tok) == 0)
			return (index);
		index++;
		current = current->next;
	}
	return (0);
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
