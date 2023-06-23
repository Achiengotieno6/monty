#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./monty.h"
/**
 * opcode_ - sets the LIFO AND FIFO FORMAT
 * @stack: stack to set format
 * @str: the string to compare with the opcodes
 * @line_number: line associated with the opcodes stack and queue
 * Return: void
 */
void opcode_(stack_t **stack, char *str, unsigned int line_number)
{
	int w = 0;
	instruction_t opcodes[] = INSTRUCTIONS;

	if (!strcmp(str, "queue"))
	{
		globalData.mode = 0;
		return;
	}
	if (!strcmp(str, "stack"))
	{
		globalData.mode = 1;
		return;
	}
	while (opcodes[w].opcode)
	{
		if (strcmp(opcodes[w].opcode, str) == 0)
		{
			opcodes[w].f(stack, line_number);
			return;
		}
		w++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
}
