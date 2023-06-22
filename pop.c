#include "monty.h"
/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!valid_stack(stack))
	{
		global.mode = 2;
		op_error(line_number, "can't pop an empty stack")
		return;
	}
	temp = *stack;

	if (temp->next != NULL)
		temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
