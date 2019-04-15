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
	register int len = 0, index = 0, i;
	linked_l *current;
	char *tmp, *ptr;

	current = head;
	while (current)
	{
		ptr = _strchr(current->string, '=');
		len = ptr - current->string;
		tmp = malloc(sizeof(char) * len + 1);
		for (i = 0; i < len; i++)
			tmp[i] = current->string[i];
		tmp[i] = '\0';
		if (_strcmp(str, tmp) == 0)
		{
			free(tmp);
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
	register int i = 0;
	linked_l *head;

	head = NULL;
	while (array[i])
	{
		addNodeEnd(&head, array[i]);
		i++;
	}
	return (head);
}

/**
 * addNodeAtIndex - add node at index with string
 * @head: double pointer to head
 * @index: index to add at
 * @str: string to add
 * Return: address of node added
 */
linked_l *addNodeAtIndex(linked_l **head, int index, char *str)
{
	register int i = 0;
	linked_l *newNode, *current;
	char *newStr;

	current = *head;
	if (!str)
		return (NULL);
	newNode  = malloc(sizeof(linked_l));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		free(newNode);
		perror("Malloc failed\n");
		exit(errno);
	}

	newNode->string = newStr;
	newNode->next = NULL;

	while (i < index - 1)
	{
		if (current->next == NULL)
		{
			free(newNode);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	newNode->next = current->next;
	current->next = newNode;
	return (newNode);
}

/**
 * getNodeAtIndex - returns the nth node of a listint_t linked list
 * @head: pointer to head of list
 * @index: index of value to be returned
 * Return: address of node at input index
 */
char *getNodeAtIndex(linked_l *head, unsigned int index)
{
	register uint count = 0;
	linked_l *current;
	char *ptr;

	current = head;
	while (current)
	{
		if (count == index)
		{
			ptr = _strdup(current->string);
			return (ptr);
		}
		count++;
		current = current->next;
	}
	return (NULL);
}
