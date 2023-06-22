#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: head of stack
 * @line_number: number of the line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!valid_stack(stack))
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		global.mode = 2;
		return;
	}
	printf("%d\n", (*stack)->n);
}
