#include <ctype.h>
#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: double pointer to the stack with char to print
 * @line_number: line no associated with the opcode pchar
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
