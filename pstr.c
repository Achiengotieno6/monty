#include "monty.h"
/**
 * pstr - prints the string on top of the stack
 * @stack: double pointer to print the string from
 * @line_number: line no. associated with the opcode
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar((char) temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
