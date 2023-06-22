#include "monty.h"
/**
 * swap - swaps two top elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!valid_top_two(stack))
	{
		global.mode = 2;
		op_error(line_number, "can't swap, stack too short");
		return;
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
