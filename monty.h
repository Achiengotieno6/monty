#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
include <stdlib.h>

#define N_OPCODES 17

/**
 * struct global - pile of useful global variables
 * @stack: top of the stack
 * @tail: bottom of the stack
 * @buf: readline buffer
 * @mode: 0 = stacking, 1 = queuing, 2 = program error, clean and exit
 */
typedef struct global_s
{
    stack_t *stack;
    stack_t *tail;
    char *buf;
    int mode;
} global_t;

extern global_t global;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
int main(int argc, char **argv);
void init_program(int argc, char **argv, FILE **fd, char **buf, size_t *bs);
void exit_clean(char *buf, FILE *fd);
void free_stack(void);
int valid_top_two(stack_t **stack);
int valid_stack(stack_t **stack);
char *find_arg1(char *buf);
char *find_arg2(char *buf);
int word_match(char *s1, char *s2);
int parse_number(void);
void error_exit(char *message);
void open_error(char *file);
void invalid_error(int line, char *opcode);
void op_error(int line, char *message)
stack_t *create_node(void);
void add(stack_t **stack, unsigned int line_number);
#endif
