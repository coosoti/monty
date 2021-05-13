#ifndef __MONTY_H_
#define __MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct qs_s - struct to contain the main variables of the Monty interpreter
 * @q_or_s: flag to determine if in stack vs queue mode
 * @qs_len: length of the stack
 */
typedef struct qs_s
{
	int q_or_s;
	size_t qs_len;
} qs_t;

#define STACK 0
#define QUEUE 1

/* global struct to hold flag for queue and stack length */
extern qs_t var;

/* Memory Management */
void free_stack(int status, void *arg);
void fs_close(int status, void *arg);
void free_line(int status, void *arg);

/* main */
void execute(char *op, stack_t **stack, unsigned int line_number);

/* helper */
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **stack, const int n);

/* opcodes */
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif
