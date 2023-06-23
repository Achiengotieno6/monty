#include "monty.h"
/**
 * mul - multiplies two elements of a stack
 * @stack: double pointer to the stack
 * @line_number: line no.
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	product = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = product;
}
