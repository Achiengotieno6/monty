#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: head of stack
 * @line_number: number of the line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
