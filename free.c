#include "monty.h"
/**
 * stackfreeing - used to free the stack (linked list)
 * @stack: pointer to the stack to free
 * Return: void
 */
void stackfreeing(stack_t *stack)
{
	stack_t *presentnode = stack;
	stack_t *nextnode;

	if (stack)
	{
		nextnode = stack->next;
		while (presentnode)
		{
			free(presentnode);
			presentnode = nextnode;
			if (nextnode)
				nextnode = nextnode->next;
		}
	}
}
