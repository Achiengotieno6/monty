#include "monty.h"
/**
 * nodeadd - adds a node on a stack
 * @stack: double pointer to the stack to add the node onto
 * @n: the valueto push on the stack
 * Return: the new node(success), NULL if it fails
 */
stack_t *nodeadd(stack_t **stack, const int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newnode);
		return (NULL);
	}
	newnode->n = n;

	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack)
		(*stack)->prev = newnode;
	*stack = newnode;

	return (newnode);
}
