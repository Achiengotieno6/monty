#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (!valid_top_two(stack))
	{
		printf("L%u: can't add, stack too short\n", line);
		global.mode = 2;
		return;
	}
	temp->next->n += temp->n;
	pop(stack, line);
}
