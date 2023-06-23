#include "monty.h"
/**
 * rotr - the last element of the stack becomes the top of the stack
 * @stack: the stack to rotate
 * @line_number: line associated with the opcode
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{

	stack_t *bottom;
	stack_t *previous;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;
	previous = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	previous->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
