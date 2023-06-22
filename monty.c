#include "monty.h"
global_t global;

/**
 * main - Main entry point
 * @argc: Number of arguments
 * @argv: Argument vector
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	char *opcode;
	unsigned int i, line_number;
	FILE *fd;
	size_t bufsize;
	instruction_t table[N_OPCODES] = {
	{"push", &push}, {"pall", &pall}, {"pint", &pint}, {"pop", &pop},
	{"swap", &swap}, {"add", &add}, {"nop", &nop}, {"sub", &sub},
	{"div", &div}, {"mul", &mul}, {"mod", &mod},	{"pchar", &pchar},
	{"pstr", &pstr}, {"rotl", &rotl}, {"rotr", &rotr}, {"stack", &stack},
	{"queue", &queue}, };
	init_program(argc, argv, &fd, &global.buf, &bufsize);
	line_number = 0;
	while (1)
	{
		if (getline(&global.buf, &bufsize, fd) == -1)
			break;
		line_number += 1;

		opcode = find_arg1(global.buf);
		if (*opcode == '\0' || *opcode == '#' || *opcode == '\n')
			continue;

		for (i = 0; i < N_OPCODES; i++)
		{
			if (word_match(table[i].opcode, opcode))
			{
				table[i].f(&global.stack, line_number);
				break;
			}
		}
		if (i >= N_OPCODES)
			global.mode = 2, invalid_error(line_number, opcode);
		if (global.mode == 2)
		{
			exit_clean(global.buf, fd);
			exit(EXIT_FAILURE);
		}
	}
	exit_clean(global.buf, fd);
	return (EXIT_SUCCESS);
}

/**
 * init_program - initiates program
 * @argc: number of arguments
 * @argv: argument vector
 * @fd: file descriptor
 * @buf: buffer to use for reading file
 * @bs: size of buffer
 */
void init_program(int argc, char **argv, FILE **fd, char **buf, size_t *bs)
{
	(void) buf;
	*bs = 0;
	*fd = fopen(argv[1], "r");
	if (argc != 2)
		error_exit("USAGE: monty file\n");
	if (*fd == NULL)
		open_error(argv[1]);
	global.mode = 0;
	global.stack = NULL;
	global.tail = NULL;
}
/**
 * exit_clean- clean up and exit the process
 * @buf: buffer to free
 * @fd: file to close
 */
void exit_clean(char *buf, FILE *fd)
{

	(void) buf;
	free(global.buf);
	free_stack();
	fclose(fd);
}
/**
 * free_stack - free all memory in the stack
 */
void free_stack(void)
{
	stack_t *temp;

	while (global.stack != NULL)
	{
		temp = global.stack;
		global.stack = (global.stack)->next;
		free(temp);
	}
}
