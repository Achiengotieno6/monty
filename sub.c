#include "monty.h"
/**
 * sub - subtracts two elements of the stack
 * @stack: double pointer to the stack containing the 2 elements
 * @line_number: line no. associated with the sub opcode
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int total_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	total_sum = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = total_sum;
}
