#include "monty.h"
/**
 * push - Push a new elemenet into the stack
 * @stack: pointer to top of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *f = globalData.arg;

	if ((is_digit(f)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (globalData.mode == 1) /*1 for stack ,0 for queue*/
	{
		if (!nodeadd(stack, atoi(globalData.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue(stack, atoi(globalData.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * pall - Print all items in the stack
 * @stack: the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_display(*my_stack);
}

/**
 * stack_display - displays the values of the stack
 * @stack: the stack to display its values
 * Return: size of the stack
 */
size_t stack_display(const stack_t *stack)
{
	size_t stack_size = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		stack_size++;
	}
	return (stack_size);
}
