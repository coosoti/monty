#include "monty.h"

/**
 * stack - change the data push mode to LIFO - stack DS
 * @head: double pointer pointing to the top of stack
 * @line_number: index of the instruction
 * Return: void
 */

void stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	glob.selector = 0;
}

/**
 * queue - change the data push mode to FIFO - queue DS
 * @head: double pointer pointing to the top of stack
 * @line_number: index of the instruction
 * Return: void
 */

void queue(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	glob.selector = 1;
}
