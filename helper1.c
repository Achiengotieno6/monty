#include "monty.h"
/**
 * error_exit - exits program when error occurs
 * @message: the info to print out
 *
 */
void error_exit(char *message)
{
	write(STDOUT_FILENO, message, strlen(message);
	exit(EXIT_FAILURE);
}
/**
 * open_error - errors occur when opening file
 * @file: file to be opened
 */
void open_error(char *file)
{
	printf("Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
/**
 * invalid_error - error in opcode
 * @line: the line error occurs
 * @opcode: the code that doesn't exist
 */
void invalid_error(int line, char *opcode)
{
	char *older;

	older = opcode;
	while (*opcoe != ' ')
	{
		if (*opcode == '\0' || *opcode == '\n')
			break;
		opcode++;
	}
	*opcode = '\0';
	printf("L%d: unknown instruction %s\n", line, old);
}
/**
 * op_error - error for opcode function
 * @line: line error occurs
 * @message: info to display
 */
void op_error(int line, char *message)
{
	printf("L%d: %s\n", line, message);
}
