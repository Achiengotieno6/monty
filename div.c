#include "monty.h"
/**
 * div - divides the two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line no. 
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
		;
		return;
	}
	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}
