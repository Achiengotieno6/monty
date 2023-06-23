#include "monty.h"
/**
 * mod - computes the rest of the division
 * @stack: double pointer to the stack
 * @line_number: line no associated with the mod opcode
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!my_stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}
