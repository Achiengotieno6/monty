#include "monty.h"
/**
 * queue - add node on the queue
 * @stack: double pointer to the stack to add onto
 * @n: the value to add on the stack
 * Return: newnode if success, NULL if failure
 */
stack_t *queue(stack_t **stack, const int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	stack_t *presentnode = *stack;

	if (!newnode)
	{
		free(newnode);
		return (NULL);
	}
	newnode->n = n;

	if (!*stack)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*stack = newnode;
		return (newnode);
	}
	while (presentnode)
	{
		if (!presentnode->next)
		{
			newnode->next = NULL;
			newnode->prev = presentnode;
			presentnode->next = newnode;
			break;
		}
		presentnode = presentnode->next;
	}
	return (newnode);
}
