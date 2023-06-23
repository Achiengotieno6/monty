#include "monty.h"
/**
 * swap - swaps two top elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node = NULL;
	int data_var = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_node = *stack;
	data_var = temp_node->n;
	temp_node->n = data_var;

	temp_node->n = temp_node->next->n;
	temp_node->next->n = data_var;
}
