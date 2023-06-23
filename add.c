#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int total;

	if (!stack || !*stack || !((*stack)->next))
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = total;
}
