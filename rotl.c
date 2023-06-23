#include "monty.h"
/**
 * rotl - top element becomes the last one, and 2nd top become first one
 * @stack: the stack to rotate the elements
 * @line_number: line no associated with the opcode
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *bottom;

	(void) line_number;
	if (!stack || !*stack || !(*stack)->next)
		return;
	bottom = top = *stack;

	while (top->next)
		top = top->next;
	top->next = bottom;
	bottom->prev = top;
	*stack = bottom->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
