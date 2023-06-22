#include "monty.h"
/**
 * create_node - creates a new node
 * Return: pointer to node
 */
stack_t *create_node(void)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_exit("Error: malloc failed");
	node->n = parse_number();
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
/**
 * push - Push a new elemenet into the stack
 * @stack: pointer to top of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		global.stack = create_node();
		if (global.mode == 2)
			printf("L%u: usage: push integer\n", line_number);
	}
	else
	{
		temp = *stack;
		global.stack = create_node();
		if (global.mode == 2)
		{
			printf("L%u: usage: push integer\n", line_number);
			return;
		}
		global.stack->next = temp;
	}
}
/**
 * pall - Print all items in the stack
 * @stack: the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t temp;

	(void) line_number;
	if (!valid_stack(stack)
		return;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
